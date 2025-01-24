#ifndef TEST_SORTING_ALGORITHM_H
#define TEST_SORTING_ALGORITHM_H

#include <stdbool.h>

bool test_Sorting_Algorithm(void (*sorting_Algorithm)(char *, int), int arraySize);

bool check_If_Sorted(char *array, int arraySize);

#endif //TEST_SORTING_ALGORITHM_H
