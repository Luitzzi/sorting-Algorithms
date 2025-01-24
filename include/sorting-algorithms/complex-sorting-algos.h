#ifndef COMPLEX_SORTING_ALGOS_H
#define COMPLEX_SORTING_ALGOS_H

void wrapped_Quicksort(char *array, int arraySize);

void quicksort(char *array, int first, int last);

void quicksort_Prepare_Partition(char *array, int first, int last, int *part);

void quicksort_Prepare_Pivot(char *array, int first, int last);

int quicksort_Get_Median_for_Pivot(int first, int last);

void wrapped_Quicksort_DualPivot(char *array, int arraySize);

void quicksort_DualPivot(char *array, int first, int last);

void dpQuicksort_Prepare_Partition(char *array, int first, int last, int *firstPivotIndex, int *secondPivotIndex);

void wrapped_Mergesort(char *array, int arraySize);

void mergesort(char *array, int first, int last);

void merge(char *array, int first, int last, int middle);

void wrapped_Mergesort_InSitu(char *array, int arraySize);

void mergesort_InSitu(char *array, int first, int last);

void merge_InSitu(char *array, int first, int last, int middle);

void mergesort_Iterativ(char *array, int arraySize);

void wrapped_Heapsort_Max(char *array, int arraySize);

void heapsort_Max(char *array, int first, int last);

void build_Heap_Max(char *array, int first, int last);

void heapify_max(char *array, int first, int last, int root);

void wrapped_Heapsort_Min(char *array, int arraySize);

void heapsort_Min(char *array, int first, int last);

void build_Heap_Min(char *array, int first, int last);

void heapify_min(char *array, int first, int last, int root);

#endif //COMPLEX_SORTING_ALGOS_H
