#include <stdio.h>
#include "../include/test/test-sorting-algorithm.h"
#include "../include/helper-functions/array-operations.h"

/* Test five randomly created arrays with positive numbers in [0;127]
 * If failed and arraysize <= 100 print the array
*/
bool test_Sorting_Algorithm(void (*sorting_Algorithm)(char *, int), int arraySize) {
    char array[arraySize];
    bool isSorted = false;
    for (int testNumber = 0; testNumber < 5; testNumber++) {
        init_Array_With_Positives(array, arraySize);
        sorting_Algorithm(array, arraySize);
        isSorted = check_If_Sorted(array, arraySize);
        if (!isSorted) {
            printf("Test %d failed!\n", testNumber + 1);
            if (arraySize <= 100)
                print_Array(array, arraySize);
            return false;
        }
    }
    printf("Test was successfull!\n");
    return true;
}

bool check_If_Sorted(char *array, int arraySize) {
    for (int i = 1; i < arraySize; ++i) {
        if (array[i - 1] > array[i])
            return false;
    }
    return true;
}
