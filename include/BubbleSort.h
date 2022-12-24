
#ifndef SORTING_VISUALIZER_BUBBLESORT_H
#define SORTING_VISUALIZER_BUBBLESORT_H

#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm {
public:
    explicit BubbleSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
