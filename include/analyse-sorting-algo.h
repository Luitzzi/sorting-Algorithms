#ifndef ANALYSE_SORTING_ALGO_H
#define ANALYSE_SORTING_ALGO_H

typedef void (*sorting_Algorithm)(char *, int);


void analyse_Runtime_Of_Sorting_Algorithm();

int get_Number_Of_Tests(int *sizesOfTestArrays);

// Input functions:

sorting_Algorithm get_Sorting_Algorithm();

sorting_Algorithm sorting_Algorithm_Wrapper(void (*sorting_Algorithm)(char *, int, int));

int *get_Sizes_Of_Testarrays(int **arrayOfArraysOfTestArraySizes);

void get_Input(char *buffer, int size);

void flush_Input_Buffer();

#endif //ANALYSE_SORTING_ALGO_H
