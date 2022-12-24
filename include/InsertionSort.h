
#ifndef SORTING_VISUALIZER_INSERTIONSORT_H
#define SORTING_VISUALIZER_INSERTIONSORT_H

#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm {
public:
    explicit InsertionSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
