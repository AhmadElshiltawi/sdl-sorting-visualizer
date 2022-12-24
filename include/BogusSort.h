
#ifndef SORTING_VISUALIZER_BOGUSSORT_H
#define SORTING_VISUALIZER_BOGUSSORT_H

#include "SortingAlgorithm.h"
#include "NumberGenerator.h"
#include <random>

class BogusSort : public SortingAlgorithm {
private:
    NumberGenerator *num_gen_;
    bool CheckSorted(std::vector<int> *number_vector);

public:
    explicit BogusSort(bool *visualizer_open, NumberGenerator *num_gen) : SortingAlgorithm(visualizer_open), num_gen_(num_gen) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
