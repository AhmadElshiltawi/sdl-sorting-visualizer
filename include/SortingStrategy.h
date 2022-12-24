
#ifndef SORTING_VISUALIZER_SORTING_STRATEGY_H
#define SORTING_VISUALIZER_SORTING_STRATEGY_H

#include "./SortingAlgorithm.h"
#include "./Common.h"

class SortingStrategy {
    SortingAlgorithm* sort_algorithm_{};

protected:
    std::vector<int> *number_vector_;
    Screen *screen_;
public:
    explicit SortingStrategy(std::vector<int>* number_vector, Screen *screen) : number_vector_(number_vector), screen_(screen) {};

    void SetStrategy(SortingAlgorithm* sort_algorithm){
        sort_algorithm_ = sort_algorithm;
    }

    bool Sort() const {
        return sort_algorithm_->Sort(number_vector_, screen_);
    }
};

#endif
