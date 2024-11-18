#include "lib-sorting-algorithms.h"

#include <limits.h>

void insertion_Sort_LeftToRight (char *array, int length) {
    int elementToInsert;
    int indexOfComparison;
    for (int i = 1; i < length; ++i) {
        elementToInsert = array[i];
        indexOfComparison = i - 1;
        while (indexOfComparison >= 0 && array[indexOfComparison] > elementToInsert) {
            array[indexOfComparison + 1] = array[indexOfComparison];
            indexOfComparison--;
        }
        array[indexOfComparison + 1] = elementToInsert;
    }
}

void insertion_Sort_RightToLeft (char *array, int length) {
    int elementToInsert;
    int j;
    for (int i = length - 2; i >= 0; --i) {
        elementToInsert = array[i];
        j = i + 1;
        while (j <= length - 1 && array[j] < elementToInsert) {
            array[j - 1] = array[j];
            j++;
        }
        array[j - 1] = elementToInsert;
    }
}

void bubble_Sort_MinToFront (char *array, int length) {
    char tmp;
    for (int i = 0; i < length; ++i) {
        for (int j = length - 2; j >= i; --j) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void bubble_Sort_MaxToEnd (char *array, int length) {
    char tmp;
    for (int i = length - 1; i >= 0; --i) {
        for (int j = 1; j <= i; ++j) {
            if (array[j-1] > array[j]) {
                tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void selection_Sort_Minimum (char *array, int length) {
    int min;
    char tmp;
    for (int i = 0; i < length; ++i) {
        min = i;
        for (int j = i; j < length; ++j) {
            if (array[j] < array[min])
                min = j;
        }
        tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}

void selection_Sort_Maximum (char *array, int length) {
    int max;
    char tmp;
    for (int i = length - 1; i >= 0; --i) {
        max = i;
        for (int j = i; j >= 0; --j) {
            if (array[j] > array[max])
                max = j;
        }
        tmp = array[max];
        array[max] = array[i];
        array[i] = tmp;
    }
}

// Efficient sorting algorithms

void wrapped_Quicksort (char *array, int arraySize) {
    quicksort(array, 0, arraySize - 1);
}

void quicksort (char *array, int first, int last) {
    int pivotIndex;
    if (first < last) {
        prepare_Partition (array, first, last, &pivotIndex);
        quicksort (array, first, pivotIndex - 1);
        quicksort (array, pivotIndex + 1, last);
    }
}

    void prepare_Partition (char *array, int first, int last, int *pivotIndex) {
        prepare_Pivot(array, first, last);
        char pivot = array[first];
        int part;
        part = first - 1;
        for (int i = first; i <= last; ++i) {
            if (array[i] <= pivot) {
                part++;
                swap(&array[i], &array[part]);
            }
        }
        swap (&array[first], &array[part]);
        *pivotIndex = part;
    }

    void prepare_Pivot (char *array, int first, int last) {
        int pivotIndex = get_Median_for_Pivot(first, last);
        swap(&array[first], &array[pivotIndex]);
    }

    int get_Median_for_Pivot (int first, int last) {
        srand(time(0));
        int firstRandomNum = (rand() % (last + 1 - first)) + first;
        int secondRandomNum = (rand() % (last + 1 - first)) + first;
        int thirdRandomNum = (rand() % (last + 1 - first)) + first;

        if (firstRandomNum >= secondRandomNum && firstRandomNum <= thirdRandomNum || firstRandomNum >= thirdRandomNum && firstRandomNum <= secondRandomNum)
            return firstRandomNum;
        else if (secondRandomNum >= firstRandomNum && secondRandomNum <= thirdRandomNum || secondRandomNum >= thirdRandomNum && secondRandomNum <= firstRandomNum)
            return secondRandomNum;
        else return thirdRandomNum;
    }

    void swap (char *a, char *b) {
        char tmp = *a;
        *a = *b;
        *b = tmp;
    }

void wrapped_Quicksort_DualPivot (char *array, int arraySize) {
    quicksort_DualPivot(array, 0, arraySize - 1);
}

void quicksort_DualPivot (char *array, int first, int last) {
    int firstPivotIndex;
    int secondPivotIndex;
    if (first < last) {
        prepare_Partition_DualPivot (array, first, last, &firstPivotIndex, &secondPivotIndex);
        quicksort_DualPivot (array, first, firstPivotIndex - 1);
        quicksort_DualPivot (array, firstPivotIndex + 1, secondPivotIndex - 1);
        quicksort_DualPivot (array, secondPivotIndex + 1, last);
    }
}

    void prepare_Partition_DualPivot (char *array, int first, int last, int *firstPivotIndex, int *secondPivotIndex) {
        //prepare_DualPivot(array, first, last);
        if (array[first] > array[last])
            swap(&array[first], &array[last]);
        char firstPivot = array[first];
        char secondPivot = array[last];

        int k = first + 1;
        int firstPart = first + 1;
        int secondPart = last - 1;

        while (k <= secondPart) {
            if (array[k] < firstPivot) {
                swap(&array[k], &array[firstPart]);
                firstPart++;
            }
            else if (array[k] >= secondPivot) {
                while (array[secondPart] > secondPivot && k < secondPart) {
                    secondPart--;
                }
                swap(&array[k], &array[secondPart]);
                secondPart--;
                if (array[k] < firstPivot) {
                    swap(&array[k], &array[firstPart]);
                    firstPart++;
                }
            }
            k++;
        }
        firstPart--;
        secondPart++;

        swap(&array[first], &array[firstPart]);
        swap(&array[last], &array[secondPart]);

        *firstPivotIndex = firstPart;
        *secondPivotIndex = secondPart;
    }

    void prepare_DualPivot (char *array, int first, int last) {
    // Problem: Selbe Zufallszahl möglich
        srand(time(0));
        int firstRandomNum = (rand() % (last - first + 1) + first);
        int secondRandomNum = (rand() % (last - first + 1) + first);

        if (firstRandomNum > secondRandomNum) {
            int tmp = firstRandomNum;
            firstRandomNum = secondRandomNum;
            secondRandomNum = tmp;
        }
        swap(&array[firstRandomNum], &array[first]);
        swap(&array[secondRandomNum], &array[last]);
    }

void wrapped_Mergesort (char *array, int arraySize) {
    mergesort(array, 0, arraySize - 1);
}

void mergesort (char *array, int first, int last) {
    if (first < last) {
        int middle = (first + last + 1) / 2;
        mergesort (array, first, middle - 1);
        mergesort (array, middle, last);
        merge (array, first, last, middle);
    }
}

    void merge (char *array, int first, int last, int middle) {
        int arraySize = last - first + 1;
        int a1f = first, a1l = middle-1;
        int a2f = middle, a2l = last;
        char newArray[arraySize];

        for (int i = 0; i < arraySize; ++i) {
            if (a1f <= a1l)
                if (a2f <= a2l)
                    if (array[a1f] <= array[a2f])
                        newArray[i] = array[a1f++];
                    else newArray[i] = array[a2f++];
                else newArray[i] = array[a1f++];
            else newArray[i] = array[a2f++];
        }
        for (int j = 0; j < arraySize; ++j) {
            array[first + j] = newArray[j];
        }
    }

void wrapped_Heapsort (char *array, int arraySize) {
    heapsort(array, 0, arraySize - 1);
}

void heapsort (char *array, int first, int last) {
    build_Heap (array, first, last);
    for (int i = last; i > first; i--) {
        swap(&array[first], &array[i]);
        heapify(array, first, i - 1, first);
    }
}

    void build_Heap (char *array, int first, int last) {
        int sizeArrayPart = last - first + 1;
        for (int i = first + (sizeArrayPart - 2) / 2; i >= first; i--) {
            heapify (array, first, last, i);
        }
    }

    void heapify (char *array, int first, int last, int root) {
        int largest;
        int left = first + (root - first) * 2 + 1;
        int right = first + (root - first) * 2 + 2;

        if (left <= last && array[left] > array[root])
            largest = left;
        else largest = root;
        if (right <= last && array[right] > array[largest])
            largest = right;
        if (largest != root) {
            swap(&array[root],&array[largest]);
            heapify (array, first, last, largest);
        }
    }

void wrapped_Countsort_Slow (char *array, int arraySize) {
    char maxValue = -127;
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] > maxValue)
            maxValue = array[i];
    }
    countsort_Slow(array,arraySize,maxValue);
}

void countsort_Slow (char *inputArray, int arraySize, int maxValue) {
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
            inputArray[inputArrayCounter] = i; // i indicates the number and bucketArray[i] how of the number occures in the input array
            bucketArray[i]--;
            inputArrayCounter++;
        }
    }
}

void wrapped_Countsort (char *array, int arraySize) {
    char maxValue = -127;
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] > maxValue)
            maxValue = array[i];
    }
    countsort(array,arraySize,maxValue);
}

void countsort (char *inputArray, int arraySize, int maxValue) {
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

void wrapped_Mapsort (char* array, int arraySize) {
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
    double distance = (double) (max-min) / (double) (increasedArraySize - 1);
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
                }
                else insertToLeftSide = false;
            }
            else {
                if (itemToInsert <= tmpArray[position]) {
                    swap(&tmpArray[position], &itemToInsert);
                }
                if (position < increasedArraySize - 1) {
                    position++;
                }
                else insertToLeftSide = true;
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