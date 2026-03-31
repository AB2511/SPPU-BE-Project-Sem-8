#include <iostream>
#include <omp.h>

using namespace std;

// -------- MIN --------
int findMin(int arr[], int n) {
    int min_val = arr[0];

    #pragma omp parallel for reduction(min:min_val)
    for(int i = 0; i < n; i++) {
        if(arr[i] < min_val)
            min_val = arr[i];
    }

    return min_val;
}

// -------- MAX --------
int findMax(int arr[], int n) {
    int max_val = arr[0];

    #pragma omp parallel for reduction(max:max_val)
    for(int i = 0; i < n; i++) {
        if(arr[i] > max_val)
            max_val = arr[i];
    }

    return max_val;
}

// -------- SUM --------
int findSum(int arr[], int n) {
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

// -------- AVERAGE --------
double findAverage(int arr[], int n) {
    int total = findSum(arr, n);
    return (double) total / n;
}

// -------- MAIN --------
int main() {

    int n = 10;
    int arr[10] = {5, 2, 9, 1, 7, 6, 3, 8, 4, 10};

    cout << "Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Minimum: " << findMin(arr, n) << endl;
    cout << "Maximum: " << findMax(arr, n) << endl;
    cout << "Sum: " << findSum(arr, n) << endl;
    cout << "Average: " << findAverage(arr, n) << endl;

    return 0;
}
