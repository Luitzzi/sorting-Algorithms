#ifndef LIB_SORTING_ALGORITHMS_H
#define LIB_SORTING_ALGORITHMS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Simple sorting algorithms
void insertion_Sort_LeftToRight (char *array, int length);
void insertion_Sort_RightToLeft (char *array, int length);
void bubble_Sort_MinToFront (char *array, int length);
void bubble_Sort_MaxToEnd (char *array, int length);
void selection_Sort_Minimum (char *array, int length);
void selection_Sort_Maximum (char *array, int length);

// Efficient sorting algorithms
void wrapped_Quicksort (char *array, int arraySize);
void quicksort (char *array, int first, int last);
    void prepare_Partition (char *array, int first, int last, int *part);
    void prepare_Pivot (char *array, int first, int last);
    int get_Median_for_Pivot (int first, int last);
    void swap (char *a, char *b);
void wrapped_Quicksort_DualPivot (char *array, int arraySize);
void quicksort_DualPivot (char *array, int first, int last);
    void prepare_Partition_DualPivot (char *array, int first, int last, int *firstPivotIndex, int *secondPivotIndex);
    void prepare_DualPivot (char *array, int first, int last);
void wrapped_Mergesort (char *array, int arraySize);
void mergesort (char *array, int first, int last);
    void merge (char *array, int first, int last, int middle);
void wrapped_Heapsort (char *array, int arraySize);
void heapsort (char *array, int first, int last);
    void build_Heap (char *array, int first, int last);
    void heapify (char *array, int first, int last, int root);
void wrapped_Countsort_Slow (char *array, int arraySize);
void countsort_Slow (char *inputArray, int arraySize, int maxValue);
void wrapped_Countsort (char *array, int arraySize);
void countsort (char *inputArray, int arraySize, int maxValue);
void wrapped_Mapsort (char* array, int arraySize);
void mapsort(char *inputArray, int arraySize, double increaseSizeRatio);


#endif