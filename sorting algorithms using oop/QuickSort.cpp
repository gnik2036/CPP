//
// Created by shady on 4/14/2018.
//

#include "QuickSort.h"

#include <algorithm>


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

QuickSorter::QuickSorter() {
}

int QuickSorter::partition(int array[], int beg, int last) {
    int mid = beg + (last - beg) / 2;    // OR el m7md 7assan function , (last+beg)/2
    int pivot = array[mid];   // ya3ny e7na hena gebna el pivot , eli hwa eli fel nos bezzabt < ya3ny esta5dem el tare2a deh msh bta3t na5od awl wa7d , wlala 7atta el median

    swap(&array[mid] , &array[beg]);

    int i = beg + 1, j = last;
    while (i <= j) {
        while(i <= j && array[i] <= pivot)  { i++; }
        while(i <= j && array[j] > pivot)   { j--; }

        if (i < j) {
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i - 1], &array[beg]);
    return i - 1;
}

void QuickSorter::Sort(int array[], int beg, int last){
    if (beg >= last) {
        return;
    }
    int part = partition(array, beg, last);
    QuickSorter::Sort(array, beg, part - 1);
    QuickSorter::Sort(array, part + 1, last);
}

void QuickSorter::Sort(int array[], int size){  // overloaded functions 3adyyyyyyyy
    QuickSorter::Sort(array, 0, size - 1);
}
