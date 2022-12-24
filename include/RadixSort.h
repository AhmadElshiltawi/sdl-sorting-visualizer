
#ifndef SORTING_VISUALIZER_RADIXSORT_H
#define SORTING_VISUALIZER_RADIXSORT_H

#include <cmath>
#include <algorithm>
#include "SortingAlgorithm.h"

class RadixSort : public SortingAlgorithm {
    std::vector<int> bucket_[10];

    void ClearBucket();
    static int number_of_digits(int number);
    static int digit_at_position(int number, int position);

public:
    explicit RadixSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
