
#ifndef SORTING_VISUALIZER_QUICKSORT_H
#define SORTING_VISUALIZER_QUICKSORT_H

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm {
private:
    int Partition(std::vector<int> *number_vector, int start, int end);
    void QuickSortRecursion(std::vector<int> *number_vector, Screen *screen, int start, int end);

public:
    explicit QuickSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
