//
// Created by shady on 4/14/2018.
//
#include "Testbed.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using  namespace std ;

Testbed::Testbed() {
}

int* Testbed::GenerateRandomList(int min, int max, int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % max + min;
    }
    return array;
}


double Testbed::RunOnce(Sorter* s, int* data, int size) {
    clock_t t = clock();
    s->Sort(data, size);
    t = clock() - t;
    return (double)(t) / CLOCKS_PER_SEC;
}

double Testbed::RunAndAverage(Sorter* s, int type, int min, int max, int size, int sets_num) {
    double sum_t = 0;
    for (int i = 0; i < sets_num; i++) {
        int *array =GenerateRandomList(min, max, size) ;
        sum_t += RunOnce(s, array, size);
        delete[] array;
    }
    return sum_t / sets_num;
}

void Testbed::RunExperiment(Sorter* s, int type, int min, int max, int min_val, int max_val, int sets_num, int step) {
    cout << setw(7) << "Set Size" << setw(15) << "Average Time" << endl;
    for (int n = min_val; n <= max_val; n += step) {
        cout << setw(7) << n << setw(15) << RunAndAverage(s, type, min, max, n, sets_num) << endl;
    }
}

