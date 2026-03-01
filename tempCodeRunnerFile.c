#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*MERGE SORT */

void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* QUICK SORT  */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int pivotChoice) {

    if(pivotChoice == 2)
        swap(&arr[low], &arr[high]);

    else if(pivotChoice == 3) {
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[low], &arr[randomIndex]);
    }

    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(1) {

        while(i <= j && arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i > j)
            break;

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high, int pivotChoice) {
    if(low < high) {
        int pi = partition(arr, low, high, pivotChoice);
        quickSort(arr, low, pi - 1, pivotChoice);
        quickSort(arr, pi + 1, high, pivotChoice);
    }
}

/*  MAIN */

int main() {

    int n;
    printf("Enter range (500 / 50000 etc): ");
    scanf("%d", &n);

    srand(time(NULL));

    /* Generate Random Input File */
    FILE *inputFile = fopen("input.txt", "w");

    for(int i = 0; i < n; i++) {
        int num = rand() % 10000;
        fprintf(inputFile, "%d ", num);
    }
    fclose(inputFile);

    /* Read File into Array */
    int *arr = (int*)malloc(n * sizeof(int));

    FILE *inFile = fopen("input.txt", "r");

    for(int i = 0; i < n; i++)
        fscanf(inFile, "%d", &arr[i]);

    fclose(inFile);

    int choice;
    printf("Choose Algorithm:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    scanf("%d", &choice);

    int pivotType = 1;

    if(choice == 2) {
        printf("Choose Pivot:\n");
        printf("1. First Element\n");
        printf("2. Last Element\n");
        printf("3. Random Element\n");
        scanf("%d", &pivotType);
    }

    clock_t start = clock();

    if(choice == 1)
        mergeSort(arr, 0, n - 1);
    else
        quickSort(arr, 0, n - 1, pivotType);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time Taken: %f seconds\n", time_taken);

    /* Write Output File */
    FILE *outFile;

    if(choice == 1)
        outFile = fopen("output_merge.txt", "w");
    else
        outFile = fopen("output_quick.txt", "w");

    for(int i = 0; i < n; i++)
        fprintf(outFile, "%d ", arr[i]);

    fclose(outFile);
    free(arr);

    printf("Sorted output saved successfully.\n");

    return 0;
}