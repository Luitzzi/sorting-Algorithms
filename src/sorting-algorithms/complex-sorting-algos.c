#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/helper-functions/sorting-utils.h"
#include "../include/sorting-algorithms/complex-sorting-algos.h"

void wrapped_Quicksort(char *array, int arraySize) {
    quicksort(array, 0, arraySize - 1);
}

void quicksort(char *array, int first, int last) {
    int pivotIndex;
    if (first < last) {
        quicksort_Prepare_Partition(array, first, last, &pivotIndex);
        quicksort(array, first, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, last);
    }
}

void quicksort_Prepare_Partition(char *array, int first, int last, int *pivotIndex) {
    quicksort_Prepare_Pivot(array, first, last);
    char pivot = array[first];
    int part;
    part = first - 1;
    for (int i = first; i <= last; ++i) {
        if (array[i] <= pivot) {
            part++;
            swap(&array[i], &array[part]);
        }
    }
    swap(&array[first], &array[part]);
    *pivotIndex = part;
}

void quicksort_Prepare_Pivot(char *array, int first, int last) {
    int pivotIndex = quicksort_Get_Median_for_Pivot(first, last);
    swap(&array[first], &array[pivotIndex]);
}

int quicksort_Get_Median_for_Pivot(int first, int last) {
    srand(time(0));
    int firstRandomNum = (rand() % (last + 1 - first)) + first;
    int secondRandomNum = (rand() % (last + 1 - first)) + first;
    int thirdRandomNum = (rand() % (last + 1 - first)) + first;

    if (firstRandomNum >= secondRandomNum && firstRandomNum <= thirdRandomNum || firstRandomNum >= thirdRandomNum &&
        firstRandomNum <= secondRandomNum)
        return firstRandomNum;
    else if (secondRandomNum >= firstRandomNum && secondRandomNum <= thirdRandomNum || secondRandomNum >= thirdRandomNum
             && secondRandomNum <= firstRandomNum)
        return secondRandomNum;
    else return thirdRandomNum;
}

void wrapped_Quicksort_DualPivot(char *array, int arraySize) {
    quicksort_DualPivot(array, 0, arraySize - 1);
}

void quicksort_DualPivot(char *array, int first, int last) {
    int firstPivotIndex;
    int secondPivotIndex;
    if (first < last) {
        dpQuicksort_Prepare_Partition(array, first, last, &firstPivotIndex, &secondPivotIndex);
        quicksort_DualPivot(array, first, firstPivotIndex - 1);
        quicksort_DualPivot(array, firstPivotIndex + 1, secondPivotIndex - 1);
        quicksort_DualPivot(array, secondPivotIndex + 1, last);
    }
}

void dpQuicksort_Prepare_Partition(char *array, int first, int last, int *firstPivotIndex, int *secondPivotIndex) {
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
        } else if (array[k] >= secondPivot) {
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

/*
void dpQuicksort_Get_Pivots(char *array, int first, int last) {
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
*/

void wrapped_Mergesort(char *array, int arraySize) {
    mergesort(array, 0, arraySize - 1);
}

void mergesort(char *array, int first, int last) {
    if (first < last) {
        int middle = (first + last + 1) / 2;
        mergesort(array, first, middle - 1);
        mergesort(array, middle, last);
        merge(array, first, last, middle);
    }
}

void merge(char *array, int first, int last, int middle) {
    int arraySize = last - first + 1;
    int a1f = first, a1l = middle - 1;
    int a2f = middle, a2l = last;
    char *newArray = (char *)malloc(arraySize * sizeof(char));
    if (!newArray) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

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

    free(newArray);
}

void wrapped_Mergesort_InSitu(char *array, int arraySize) {
    mergesort_InSitu(array, 0, arraySize - 1);
}

void mergesort_InSitu(char *array, int first, int last) {
    if (first < last) {
        int middle = (first + last + 1) / 2;
        mergesort_InSitu(array, first, middle - 1);
        mergesort_InSitu(array, middle, last);
        merge_InSitu(array, first, last, middle);
    }
}

/* Merging in a similar way to the ex-situ Mergesort. However, all simple-sorting-algos could be used too,
 * due to the fact that the complexity is O(n^2) any way.
 */
void merge_InSitu(char *array, int first, int last, int middle) {
    int a1f = first, a1l = middle - 1;
    int a2f = middle, a2l = last;

    while (a1f <= a1l && a2f <= a2l) {
        if (array[a1f] <= array[a2f]) {
            // Already in order
            a1f++;
        }
        else {
            // Shift all elements one to the right and swap a2f to the position of a1f
            int tmp = array[a2f];
            int k = a2f;
            while (k >= a1f) {
                array[k] = array[k - 1];
                k--;
            }
            array[a1f] = tmp;
            // Update all pointers:
            a1f++;
            a1l++;
            a2f++;
        }
    }
}

void mergesort_Iterativ(char *array, int arraySize) {
    int currentSize = 1;
    while (currentSize < arraySize) {
        int left = 0;
        while (left < arraySize) {
            int middle = min(left + currentSize, arraySize - 1);
            int last = min(left + 2 * currentSize - 1, arraySize - 1);
            merge(array, left, last, middle);
            left += 2 * currentSize;
        }
        currentSize *= 2;
    }
}

void wrapped_Heapsort_Max(char *array, int arraySize) {
    heapsort_Max(array, 0, arraySize - 1);
}

void heapsort_Max(char *array, int first, int last) {
    build_Heap_Max(array, first, last);
    for (int i = last; i > first; i--) {
        swap(&array[first], &array[i]);
        heapify_max(array, first, i - 1, first);
    }
}

void build_Heap_Max(char *array, int first, int last) {
    int sizeArrayPart = last - first + 1;
    for (int i = first + (sizeArrayPart - 2) / 2; i >= first; i--) {
        heapify_max(array, first, last, i);
    }
}

void heapify_max(char *array, int first, int last, int root) {
    int largest = root;
    int left = first + (root - first) * 2 + 1;
    int right = first + (root - first) * 2 + 2;

    if (left <= last && array[left] > array[root]) {
        largest = left;
    }
    if (right <= last && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != root) {
        swap(&array[root], &array[largest]);
        heapify_max(array, first, last, largest);
    }
}

void wrapped_Heapsort_Min(char *array, int arraySize) {
    heapsort_Min(array, 0, arraySize - 1);
}

void heapsort_Min(char *array, int first, int last) {
    build_Heap_Min(array, first, last);
    for (int i = last; i > first; i--) {
        swap(&array[first], &array[i]);
        heapify_min(array, first, i - 1, first);
    }
    invert(array, last + 1);
}

void build_Heap_Min(char *array, int first, int last) {
    int sizeArrayPart = last - first + 1;
    for (int i = first + (sizeArrayPart - 2) / 2; i >= first; i--) {
        heapify_min(array, first, last, i);
    }
}

void heapify_min(char *array, int first, int last, int root) {
    int smallest;
    int left = first + (root - first) * 2 + 1;
    int right = first + (root - first) * 2 + 2;

    if (left <= last && array[left] <= array[root]) {
        smallest = left;
    }
    else {
        smallest = root;
    }
    if (right <= last && array[right] < array[smallest]) {
        smallest = right;
    }
    if (smallest != root) {
        swap(&array[smallest], &array[root]);
        heapify_min(array, first, last, smallest);
    }
}
