#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/helper-functions/sorting-utils.h"
#include "../include/sorting-algorithms/special-sorting-algos.h"


void wrapped_Countsort_Slow(char *array, int arraySize) {
    char maxValue = -127;
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] > maxValue)
            maxValue = array[i];
    }
    countsort_Slow(array, arraySize, maxValue);
}

void countsort_Slow(char *inputArray, int arraySize, int maxValue) {
    int bucketArraySize = maxValue + 1;
    short bucketArray[bucketArraySize];
    // Initialize buckerArray with 0
    for (int i = 0; i < bucketArraySize; ++i) {
        bucketArray[i] = 0;
    }
    // Count occurences of numbers in the inputArray
    for (int i = 0; i < arraySize; ++i) {
        bucketArray[inputArray[i]]++;
    }

    // Convert the bucketArray into a sorted array
    int inputArrayCounter = 0;
    for (int i = 0; i < bucketArraySize; ++i) {
        while (bucketArray[i] != 0) {
            inputArray[inputArrayCounter] = i;
            // i indicates the number and bucketArray[i] how of the number occures in the input array
            bucketArray[i]--;
            inputArrayCounter++;
        }
    }
}

void wrapped_Countsort(char *array, int arraySize) {
    char maxValue = -127;
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] > maxValue)
            maxValue = array[i];
    }
    countsort(array, arraySize, maxValue);
}

void countsort(char *inputArray, int arraySize, int maxValue) {
    int bucketArraySize = maxValue + 1;
    unsigned int bucketArray[bucketArraySize];
    // Initialize bucketArray with 0
    for (int i = 0; i < bucketArraySize; ++i) {
        bucketArray[i] = 0;
    }
    // Count occurences of numbers in the inputArray
    int sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        bucketArray[inputArray[i]]++;
    }
    // Build the sum of the occurences
    for (int i = 1; i < bucketArraySize; ++i) {
        bucketArray[i] += bucketArray[i - 1];
    }
    // Insert the numbers into the sorted array
    char sortedArray[arraySize];
    for (int i = arraySize - 1; i >= 0; --i) {
        sortedArray[(bucketArray[inputArray[i]] - 1)] = inputArray[i];
        bucketArray[inputArray[i]]--;
    }
    for (int i = 0; i < arraySize; ++i) {
        inputArray[i] = sortedArray[i];
    }
}

void wrapped_Mapsort(char *array, int arraySize) {
    double increaseSizeRatio = 1.3;
    mapsort(array, arraySize, increaseSizeRatio);
}

void mapsort(char *inputArray, int arraySize, double increaseSizeRatio) {
    int increasedArraySize = arraySize * increaseSizeRatio;
    char tmpArray[increasedArraySize];
    int max = INT_MIN, min = INT_MAX;
    // Initialise new Array with -1 -> Value indicating the array position is empty
    for (int i = 0; i < increasedArraySize; ++i) {
        tmpArray[i] = -1;
    }
    // Get the min/max values
    for (int i = 0; i < arraySize; ++i) {
        if (inputArray[i] > max)
            max = inputArray[i];
        if (inputArray[i] < min)
            min = inputArray[i];
    }
    // Get the distance between min and max
    double distance = (double) (max - min) / (double) (increasedArraySize - 1);
    int position, itemToInsert;
    bool insertToLeftSide;
    for (int i = 0; i < arraySize; ++i) {
        // Calc position of number
        position = (int) ((double) (inputArray[i] - min) / distance);
        itemToInsert = inputArray[i];
        insertToLeftSide = false;
        // Check if position is already used & direction to insert is left
        if (tmpArray[position] != -1 && itemToInsert <= tmpArray[position])
            insertToLeftSide = true;
        while (tmpArray[position] != -1) {
            if (insertToLeftSide) {
                if (itemToInsert > tmpArray[position]) {
                    swap(&tmpArray[position], &itemToInsert);
                }
                if (position > 0) {
                    position--;
                } else insertToLeftSide = false;
            } else {
                if (itemToInsert <= tmpArray[position]) {
                    swap(&tmpArray[position], &itemToInsert);
                }
                if (position < increasedArraySize - 1) {
                    position++;
                } else insertToLeftSide = true;
            }
        }
        tmpArray[position] = itemToInsert;
    }
    // Copy the sorted result into the input array
    int inputArrayIndex = 0;
    for (int i = 0; i < increasedArraySize; ++i) {
        if (tmpArray[i] != -1) {
            inputArray[inputArrayIndex] = tmpArray[i];
            inputArrayIndex++;
        }
    }
}
