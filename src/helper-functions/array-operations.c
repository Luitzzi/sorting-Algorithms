#include "../../include/helper-functions/array-operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_ELEMENT_LIMIT 127

// [-127;127] -> To fit into char
void init_Array_With_Positiv_And_Negativ(char *array, int arraySize) {
    srand(time(0));
    for (int i = 0; i < arraySize; ++i) {
        array[i] = (char) pow(-1, rand() % 2) * (rand() % ARRAY_ELEMENT_LIMIT);
    }
}

// [0,127]
void init_Array_With_Positives(char *array, int arraySize) {
    srand(time(0));
    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % ARRAY_ELEMENT_LIMIT;
    }
}

void print_Array(char *array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d : ", array[i]);
    }
    printf("\n");
}
