//
// Created by shady on 4/14/2018.
//

#ifndef OOPASS2_QUICKSORT_H
#define OOPASS2_QUICKSORT_H
#include "Sorter.h"

class QuickSorter : public Sorter
{
private:
    int partition(int array[], int beg, int last);
    void Sort(int array[], int beg, int last);

public:
    QuickSorter();
    void Sort(int array[], int size);
};

#endif //OOPASS2_QUICKSORT_H
