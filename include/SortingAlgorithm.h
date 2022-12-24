
#ifndef SORTING_VISUALIZER_SORTING_ALGORITHM_H
#define SORTING_VISUALIZER_SORTING_ALGORITHM_H

#include "./Common.h"
#include "./Screen.h"

class SortingAlgorithm {
protected:
    bool *visualizer_open_;
    bool exit_prematurely_ = false;

    void HandleAlgorithmEvents();
    void Swap(std::vector<int> *number_vector, int index_1, int index_2);

    void PerformScreenActions(std::vector<int> *number_vector, Screen screen);
    void PerformScreenActions(std::vector<int> *number_vector, Screen screen, int x_highlight);
    void PerformScreenActions(std::vector<int> *number_vector, Screen screen, int x1_highlight, int x2_highlight);

public:
    explicit SortingAlgorithm(bool *visualizer_open) : visualizer_open_(visualizer_open) {};
    virtual bool Sort(std::vector<int> *number_vector, Screen *screen) = 0;
};

#endif
