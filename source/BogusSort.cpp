
#include "../include/BogusSort.h"
#include <algorithm>

bool BogusSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    while (!CheckSorted(number_vector)) {
        num_gen_->ShuffleVector(number_vector);

        PerformScreenActions(number_vector, *screen);

        if (!(*visualizer_open_) || exit_prematurely_) {
            exit_prematurely_ = false;
            return false;
        }
    }
    return true;
}

bool BogusSort::CheckSorted(std::vector<int> *number_vector) {
    return std::is_sorted(number_vector->begin(), number_vector->end());
}
