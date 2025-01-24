#include "../include/sorting-algorithms/simple-sorting-algos.h"

void insertion_Sort_LeftToRight(char *array, int length) {
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

void insertion_Sort_RightToLeft(char *array, int length) {
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

void bubble_Sort_MinToFront(char *array, int length) {
    char tmp;
    for (int i = 0; i < length; ++i) {
        for (int j = length - 2; j >= i; --j) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void bubble_Sort_MaxToEnd(char *array, int length) {
    char tmp;
    for (int i = length - 1; i >= 0; --i) {
        for (int j = 1; j <= i; ++j) {
            if (array[j - 1] > array[j]) {
                tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void selection_Sort_Minimum(char *array, int length) {
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

void selection_Sort_Maximum(char *array, int length) {
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
