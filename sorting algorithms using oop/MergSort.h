//
// Created by shady on 4/14/2018.
//

#ifndef OOPASS2_MERGSORT_H
#define OOPASS2_MERGSORT_H
#include "Sorter.h"

class MergSort : public Sorter
{
private:
    int partition(int arr[], int l, int m, int r);
    void Sort(int arr[], int l, int r);

public:
    MergSort();
    void Sort(int array[], int size);
};

#endif //OOPASS2_MERGSORT_H
