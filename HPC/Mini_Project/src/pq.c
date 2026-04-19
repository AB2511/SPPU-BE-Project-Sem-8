#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char* argv[]) {
    int rank, size;
    int n = 1000000;  // total elements

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int* arr = NULL;

    if (rank == 0) {
        arr = (int*)malloc(n * sizeof(int));
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000;
    }

    int local_n = n / size;
    int* local_arr = (int*)malloc(local_n * sizeof(int));

    double start = MPI_Wtime();

    // Scatter data
    MPI_Scatter(arr, local_n, MPI_INT,
                local_arr, local_n, MPI_INT,
                0, MPI_COMM_WORLD);

    // Local sort
    qsort(local_arr, local_n, sizeof(int), compare);

    // Gather back
    MPI_Gather(local_arr, local_n, MPI_INT,
               arr, local_n, MPI_INT,
               0, MPI_COMM_WORLD);

    // Final merge sort at root
    if (rank == 0) {
        qsort(arr, n, sizeof(int), compare);

        double end = MPI_Wtime();
        printf("Time taken with %d processes: %f seconds\n", size, end - start);
    }

    free(local_arr);
    if (rank == 0) free(arr);

    MPI_Finalize();
    return 0;
}
