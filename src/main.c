#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "lib-sorting-algorithms.h"
#include "lib-array-operations.h"

// Analysing functions
void analyse_Runtime_Of_Sorting_Algorithm ();
bool test_Sorting_Algorithm (void (*sorting_Algorithm)(char *, int), int arraySize);

// Helper runtime analysis functions
double meassure_Time (void (*sorting_Algorithm) (char *, int), int arraySize);
typedef void (*sorting_Algorithm)(char*,int);
sorting_Algorithm get_Sorting_Algorithm ();
sorting_Algorithm sorting_Algorithm_Wrapper (void (*sorting_Algorithm)(char *, int, int));
int *get_Sizes_Of_Testarrays (int **arrayOfArraysOfTestArraySizes);
int get_Number_Of_Tests (int *sizesOfTestArrays);
int get_Termination_Time ();

// Input helper functions
void get_Input (char *buffer, int size);
int extract_Number_From_String (char *string);
void flush_Input_Buffer ();

enum orderArraysOfTestArraySizes {HUGE_NUMBERS, BIG_NUMBERS, SMALL_NUMBERS};


int main(void) {
    analyse_Runtime_Of_Sorting_Algorithm();

    return 0;
}

bool test_Sorting_Algorithm (void (*sorting_Algorithm)(char *, int), int arraySize) {
    char array[arraySize];
    bool isSorted = false;
    for (int testNumber = 0; testNumber < 5; testNumber++)
    {
        init_Array_With_Positives (array, arraySize);
        sorting_Algorithm(array, arraySize);
        isSorted = check_If_Sorted(array, arraySize);
        if (!isSorted)
        {
            printf("Test %d failed!\n", testNumber + 1);
            if (arraySize <= 100)
                print_Array(array, arraySize);
            return false;
        }
    }
    printf("Test was successfull!\n");
    return true;
}

void analyse_Runtime_Of_Sorting_Algorithm () {
    printf("\nWelcome to the sorting-algorithm-time-meassurer :D\n");
    void (*sorting_Algorithm)(char*,int);
    int *sizesOfTestArrays;
    // A negative number indicates the end of the array
    int hugeTestArraySizes[] = {50000000,100000000,200000000,500000000,1000000000,-1};
    int bigTestArraySizes[] = {50000,100000,500000,1000000,3000000,6000000,9000000,-1};
    int smallTestArraySizes[] = {5000,10000,50000,100000,150000,200000,250000,-1};
    // Order specified in the global array "orderArraysOfTestsArraySizes"
    int *arrayOfArraysOfTestArraySizes[] = {hugeTestArraySizes, bigTestArraySizes,smallTestArraySizes};
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

double meassure_Time (void (*sorting_Algorithm) (char *, int), int arraySize) {
    clock_t start, end;
    double cpuTimeUsed;
    char *array = (char *) malloc (arraySize * sizeof(char));
    init_Array_With_Positives (array, arraySize);

    start = clock();
    (*sorting_Algorithm)(array, arraySize);
    end = clock();
    cpuTimeUsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("The Algorithm sorted %d numbers in: %lf seconds\n", arraySize, cpuTimeUsed);
    return cpuTimeUsed;
}

sorting_Algorithm get_Sorting_Algorithm () {
    int maxInputLength = 3;
    char tmpInput[maxInputLength];

    printf("\n\nPlease choose the sorting algorithm:\n(1) Bubble ; (2) Insertion ; (3) Selection ; (4) Quicksort ; (5) Dual-Pivot Quicksort ; (6) Mergesort ; (7) Heapsort ; (8) Countsort ; (9) Mapsort ;\n");
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
            return wrapped_Heapsort;
        case 8:
            return wrapped_Countsort;
        case 9:
            return wrapped_Mapsort;
    }
}

int *get_Sizes_Of_Testarrays (int **arrayOfArraysOfTestArraySizes) {
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

int get_Number_Of_Tests (int *sizesOfTestArrays) {
    int arrayLength = 0;
    // A negative number indicates the end of the array of sizes of the test arrays.
    while (sizesOfTestArrays[arrayLength] >= 0) {
        arrayLength++;
    }
    return arrayLength;
}

int get_Termination_Time () {
    int maxInputLength = 5;
    char tmpInput[maxInputLength];

    printf("After how many minutes should the sorting terminate? ( <9999Min)\n");
    get_Input(tmpInput, maxInputLength);
    return atoi(tmpInput);
}

void get_Input (char *buffer, int size) {
    printf("Enter input: ");
    if (fgets(buffer, size, stdin) != NULL){
        int inputLength = strlen(buffer);
        if (inputLength > 0 && buffer[inputLength - 1] == '\n')
            buffer[inputLength - 1] = '\0';
    }
    else {
        printf("Error reading the input! Try again: \n");
        get_Input(buffer, size);
    }
}

void flush_Input_Buffer () {
    char flusher;
    while ((flusher = getchar()) != '\n' && flusher != EOF);
}

