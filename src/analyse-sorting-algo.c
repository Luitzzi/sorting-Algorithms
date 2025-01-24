#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/analyse-sorting-algo.h"
#include "../include/sorting-algorithms/all-sorting-algos.h"
#include "../include/time-measuring.h"

enum orderArraysOfTestArraySizes { HUGE_NUMBERS, BIG_NUMBERS, SMALL_NUMBERS };

void analyse_Runtime_Of_Sorting_Algorithm() {
    printf("\nWelcome to the sorting-algorithm-time-meassurer :D\n");
    void (*sorting_Algorithm)(char *, int);
    int *sizesOfTestArrays;
    // A negative number indicates the end of the array
    int hugeTestArraySizes[] = {50000000, 100000000, 200000000, 500000000, 1000000000, -1};
    int bigTestArraySizes[] = {50000, 100000, 500000, 1000000, 3000000, 6000000, 9000000, -1};
    int smallTestArraySizes[] = {5000, 10000, 50000, 100000, 150000, 200000, 250000, -1};
    // Order specified in the global array "orderArraysOfTestsArraySizes"
    int *arrayOfArraysOfTestArraySizes[] = {hugeTestArraySizes, bigTestArraySizes, smallTestArraySizes};
    int numberOfTests = 0;
    int maxWaitingTimeMin = 0;

    sorting_Algorithm = get_Sorting_Algorithm();
    sizesOfTestArrays = get_Sizes_Of_Testarrays(arrayOfArraysOfTestArraySizes);
    numberOfTests = get_Number_Of_Tests(sizesOfTestArrays);
    maxWaitingTimeMin = get_Termination_Time();

    for (int i = 0; i < numberOfTests; ++i) {
        meassure_Time(sorting_Algorithm, sizesOfTestArrays[i]);
    }
}

int get_Number_Of_Tests(int *sizesOfTestArrays) {
    int arrayLength = 0;
    // A negative number indicates the end of the array of sizes of the test arrays.
    while (sizesOfTestArrays[arrayLength] >= 0) {
        arrayLength++;
    }
    return arrayLength;
}

// Input functions:

sorting_Algorithm get_Sorting_Algorithm() {
    int maxInputLength = 3;
    char tmpInput[maxInputLength];

    printf(
        "\n\nPlease choose the sorting algorithm:\n(1) Bubble ; (2) Insertion ; (3) Selection ; (4) Quicksort ; (5) Dual-Pivot Quicksort ; (6) Mergesort ; (7) Heapsort ; (8) Countsort-Slow ; (9) Countsort ; (10) Mapsort ;\n");
    char choice = 0;
    get_Input(tmpInput, maxInputLength);
    choice = atoi(&tmpInput[0]);

    switch (choice) {
        case 1:
            return bubble_Sort_MinToFront;
        case 2:
            return insertion_Sort_LeftToRight;
        case 3:
            return selection_Sort_Minimum;
        case 4:
            return wrapped_Quicksort;
        case 5:
            return wrapped_Quicksort_DualPivot;
        case 6:
            return wrapped_Mergesort;
        case 7:
            return wrapped_Heapsort_Max;
        case 8:
            return wrapped_Countsort_Slow;
        case 9:
            return wrapped_Countsort;
        case 10:
            return wrapped_Mapsort;
    }
}

int *get_Sizes_Of_Testarrays(int **arrayOfArraysOfTestArraySizes) {
    int maxInputLength = 3;
    char tmpInput[maxInputLength];

    printf("Would you like to use small (s), big (b) or huge (h) array sizes:\n");
    char inputArraySize;
    get_Input(tmpInput, maxInputLength);
    inputArraySize = tmpInput[0];
    switch (inputArraySize) {
        case 's':
            return arrayOfArraysOfTestArraySizes[SMALL_NUMBERS];
        case 'b':
            return arrayOfArraysOfTestArraySizes[BIG_NUMBERS];
        case 'h':
            return arrayOfArraysOfTestArraySizes[HUGE_NUMBERS];
    }
}

void get_Input(char *buffer, int size) {
    printf("Enter input: ");
    if (fgets(buffer, size, stdin) != NULL) {
        int inputLength = strlen(buffer);
        if (inputLength > 0 && buffer[inputLength - 1] == '\n')
            buffer[inputLength - 1] = '\0';
    } else {
        printf("Error reading the input! Try again: \n");
        get_Input(buffer, size);
    }
}

void flush_Input_Buffer() {
    char flusher;
    while ((flusher = getchar()) != '\n' && flusher != EOF);
}