//
// Created by shady on 4/14/2018.
//
#include " bubbleSort.h"
#include <algorithm>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


bubblesort::bubblesort() {}

void bubblesort::Sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                Swap(&arr[j], &arr[j+1]);
}
