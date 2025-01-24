#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/time-measuring.h"
#include "../include/helper-functions/array-operations.h"
#include "../include/analyse-sorting-algo.h"

double meassure_Time(void (*sorting_Algorithm)(char *, int), int arraySize) {
    clock_t start, end;
    double cpuTimeUsed;
    char *array = (char *) malloc(arraySize * sizeof(char));
    init_Array_With_Positives(array, arraySize);

    start = clock();
    (*sorting_Algorithm)(array, arraySize);
    end = clock();
    cpuTimeUsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("The Algorithm sorted %d numbers in: %lf seconds\n", arraySize, cpuTimeUsed);
    return cpuTimeUsed;
}

int get_Termination_Time() {
    int maxInputLength = 5;
    char tmpInput[maxInputLength];

    printf("After how many minutes should the sorting terminate? ( <9999Min)\n");
    get_Input(tmpInput, maxInputLength);
    return atoi(tmpInput);
}