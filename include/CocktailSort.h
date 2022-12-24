
#ifndef SORTING_VISUALIZER_COCKTAILSORT_H
#define SORTING_VISUALIZER_COCKTAILSORT_H

#include "SortingAlgorithm.h"

class CocktailSort  : public SortingAlgorithm {
public:
    explicit CocktailSort(bool *visualizer_open) : SortingAlgorithm(visualizer_open) {};
    bool Sort(std::vector<int> *number_vector, Screen *screen) override;
};


#endif
