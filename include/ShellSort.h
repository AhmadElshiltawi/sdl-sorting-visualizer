
#ifndef SORTING_VISUALIZER_SHELLSORT_H
#define SORTING_VISUALIZER_SHELLSORT_H


#include "SortingAlgorithm.h"

class ShellSort : public SortingAlgorithm {
public:
    explicit ShellSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};



#endif
