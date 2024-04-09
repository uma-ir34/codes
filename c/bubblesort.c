#include <stdio.h>

void bubbleSort(int arr[], int n, int *opcount) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // Flag to check if any swap occurred in this pass
        for (int j = 0; j < n - i - 1; j++) {
            (*opcount)++; // Increment the operation count for each comparison

            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*opcount)++; // Increment the operation count for each swap
                swapped = 1;
            }
        }

        // If no swap occurred in this pass, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n], bestCase[n], worstCase[n];
    int opcountBest = 0, opcountWorst = 0;

    // Input array from the user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Best Case: Already sorted array
    for (int i = 0; i < n; i++) {
        bestCase[i] = arr[i];
    }

    // Worst Case: Reverse sorted array
    for (int i = 0; i < n; i++) {
        worstCase[i] = arr[n - i - 1];
    }

    // Bubble Sort on Best Case
    bubbleSort(bestCase, n, &opcountBest);
    printf("\nSorted Array (Best Case): ");
    printArray(bestCase, n);
    printf("Operation Count (Best Case): %d\n", opcountBest);

    // Bubble Sort on Worst Case
    bubbleSort(worstCase, n, &opcountWorst);
    printf("\nSorted Array (Worst Case): ");
    printArray(worstCase, n);
    printf("Operation Count (Worst Case): %d\n", opcountWorst);

    return 0;
}
