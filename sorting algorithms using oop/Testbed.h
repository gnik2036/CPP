//
// Created by shady on 4/14/2018.
//

#ifndef OOPASS2_TESTBED_H
#define OOPASS2_TESTBED_H
#include "Sorter.h"

class Testbed {
public:
    Testbed();
    int* GenerateRandomList(int min, int max, int size);
    double RunOnce(Sorter* sorter, int* data, int size);
    double RunAndAverage(Sorter* sorter, int type, int min, int max, int size, int sets_num);
    void RunExperiment(Sorter* sorter, int type, int min, int max, int min_val, int max_val, int sets_num, int step);
};

#endif //OOPASS2_TESTBED_H
