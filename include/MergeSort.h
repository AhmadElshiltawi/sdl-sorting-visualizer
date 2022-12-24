
#ifndef SORTING_VISUALIZER_MERGESORT_H
#define SORTING_VISUALIZER_MERGESORT_H

#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm {
private:
    void Merge(std::vector<int> *number_vector, int start, int mid, int end);
    void MergeSortRecursion(std::vector<int> *number_vector, Screen *screen, int start, int end);

public:
    explicit MergeSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
