#include "lib-array-operations.h"

bool check_If_Sorted (char *array, int arraySize) {
    for (int i = 1; i < arraySize; ++i) {
        if (array[i-1] > array[i])
            return false;
    }
    return true;
}

void init_Array_With_Positiv_And_Negativ (char *array, int arraySize) {
    srand(time(0));
    for (int i = 0; i < arraySize; ++i) {
        array[i] = (char) pow(-1, rand()%2) * (rand() % 128);
    }
}

void init_Array_With_Positives (char *array, int arraySize) {
    srand(time(0));
    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % 128;
    }
}

void print_Array (char *array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d : ", array[i]);
    }
    printf("\n");
}