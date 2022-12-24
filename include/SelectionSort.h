
#ifndef SORTING_VISUALIZER_SELECTIONSORT_H
#define SORTING_VISUALIZER_SELECTIONSORT_H

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm {
public:
    explicit SelectionSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
