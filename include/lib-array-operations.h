#ifndef LIB_ARRAY_OPERATIONS_H
#define LIB_ARRAY_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool test_Sorting_Algorithm (void (*sorting_Algorithm)(char *, int));
bool check_If_Sorted (char *array, int arraySize);
void init_Array_With_Positiv_And_Negativ (char *array, int arraySize);
void init_Array_With_Positives (char *array, int arraySize);
void print_Array (char *array, int arraySize);

#endif