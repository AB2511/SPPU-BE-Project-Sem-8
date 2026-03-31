#include <iostream>
#include <omp.h>

using namespace std;

// -------- Sequential Bubble Sort --------
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// -------- Parallel Bubble Sort --------
void parallelBubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {

        // Even phase
        #pragma omp parallel for
        for(int j = 0; j < n-1; j += 2) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }

        // Odd phase
        #pragma omp parallel for
        for(int j = 1; j < n-1; j += 2) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// -------- Merge Function --------
void merge(int arr[], int l, int m, int r) {
    int i = l, j = m+1;
    int temp[100];

    int k = 0;

    while(i <= m && j <= r) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= m)
        temp[k++] = arr[i++];

    while(j <= r)
        temp[k++] = arr[j++];

    for(int i = l, j = 0; i <= r; i++, j++)
        arr[i] = temp[j];
}

// -------- Sequential Merge Sort --------
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// -------- Parallel Merge Sort --------
void parallelMergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(arr, l, m);

            #pragma omp section
            parallelMergeSort(arr, m+1, r);
        }

        merge(arr, l, m, r);
    }
}

// -------- Print Array --------
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// -------- MAIN --------
int main() {

    int n = 100;
    int arr1[n], arr2[n];

    // Initialize array (reverse order)
    for(int i = 0; i < n; i++) {
        arr1[i] = n - i;
        arr2[i] = n - i;
    }

    double start, end;

    // -------- Sequential Bubble --------
    start = omp_get_wtime();
    bubbleSort(arr1, n);
    end = omp_get_wtime();

    cout << "Sequential Bubble Sort Time: " << end - start << endl;
    printArray(arr1, n);

    // Reset
    for(int i = 0; i < n; i++)
        arr1[i] = n - i;

    // -------- Parallel Bubble --------
    start = omp_get_wtime();
    parallelBubbleSort(arr1, n);
    end = omp_get_wtime();

    cout << "Parallel Bubble Sort Time: " << end - start << endl;
    printArray(arr1, n);

    // -------- Sequential Merge --------
    start = omp_get_wtime();
    mergeSort(arr2, 0, n-1);
    end = omp_get_wtime();

    cout << "Sequential Merge Sort Time: " << end - start << endl;
    printArray(arr2, n);

    // Reset
    for(int i = 0; i < n; i++)
        arr2[i] = n - i;

    // -------- Parallel Merge --------
    start = omp_get_wtime();
    parallelMergeSort(arr2, 0, n-1);
    end = omp_get_wtime();

    cout << "Parallel Merge Sort Time: " << end - start << endl;
    printArray(arr2, n);

    return 0;
}
