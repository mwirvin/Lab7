/*
Michael Irvin
3/7/2024
Lab 7
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
    int numswaps;
} element;

element* numSwapsBubbleSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element) * size);
    // initialize element array with the data from the input array
    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    // given hint from discord
    // W hints btw
    
    int totalSwaps = 0;
    // Bubble sort algo
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (swaps[j].data > swaps[j + 1].data) {
                // swappint elements
                element temp = swaps[j];
                swaps[j] = swaps[j + 1];
                swaps[j + 1] = temp;
                
                // incrementing the swap counts
                swaps[j].numswaps++;
                swaps[j + 1].numswaps++;
                totalSwaps++;
            }
        }
    }
    printf("Total swaps (Bubble Sort): %d\n", totalSwaps);
    return swaps;
}



element* numSwapsSelectionSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element) * size);
    for (int i = 0; i < size; i++) {
        // gives element struct the data from the given input arrays
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    
    int totalSwaps = 0;
    // selection sort algo
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (swaps[j].data < swaps[min_idx].data) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // swap
            element temp = swaps[i];
            swaps[i] = swaps[min_idx];
            swaps[min_idx] = temp;
            
            // swap counts
            swaps[i].numswaps++;
            swaps[min_idx].numswaps++;
            totalSwaps++;
        }
    }
    printf("Total swaps (Selection Sort): %d\n", totalSwaps);
    return swaps; // returns array of element structs that provides swap counts
}


// display
void printSwaps(element* swaps, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", swaps[i].data, swaps[i].numswaps);
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size1 = sizeof(array1) / sizeof(array1[0]);

    printf("Array 1 Bubble Sort Swaps:\n");
    element* swaps1 = numSwapsBubbleSort(array1, size1);
    printSwaps(swaps1, size1);
    free(swaps1); // so free
    printf("\n");


    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    printf("Array 2 Bubble Sort Swaps:\n");
    element* swaps2 = numSwapsBubbleSort(array2, size2);
    printSwaps(swaps2, size2);
    free(swaps2); // so free
    printf("\n");


    // Re-initialize arrays for Selection Sort
    int array1Selection[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};

    printf("Array 1 Selection Sort Swaps:\n");
    element* swaps1Selection = numSwapsSelectionSort(array1Selection, size1);
    printSwaps(swaps1Selection, size1);
    free(swaps1Selection); // so free
    printf("\n");


    int array2Selection[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("Array 2 Selection Sort Swaps:\n");
    element* swaps2Selection = numSwapsSelectionSort(array2Selection, size2);
    printSwaps(swaps2Selection, size2);
    free(swaps2Selection); // free

    return 0;
}
