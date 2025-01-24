void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    return b;
}

void invert(char *array, int arraySize) {
    int start = 0;
    int end = arraySize - 1;
    while (start < end) {
        swap(&array[start], &array[end]);
        start++;
        end--;
    }
}