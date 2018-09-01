#include <iostream>
#include "Testbed.h"
#include " bubbleSort.h"
#include "QuickSort.h"
#include"MergSort.h"

using namespace std ;


int main() {

    MergSort s1;
    QuickSorter s2;
    bubblesort s3;
    Testbed test ;
    cout << "Merg Sort Time:" << endl;
    test.RunExperiment(&s1, 0, 1, 1000000, 1000, 10000, 100, 1000);
    cout << endl;

    cout << "Quick Sort Time:" << endl;
    test.RunExperiment(&s2, 0, 1, 1000000, 1000, 10000, 100, 1000);
    cout << endl;

    cout << "bubble Sort Time:" << endl;
    test.RunExperiment(&s3, 0, 1, 1000000, 1000, 10000, 100, 1000);
    cout << endl;

    return 0;
}