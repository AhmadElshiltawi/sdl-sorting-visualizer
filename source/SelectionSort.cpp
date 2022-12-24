#include "../include/SelectionSort.h"

bool SelectionSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();
    int minimum_index = -1;

    for (int i = 0; i < vector_size - 1; i++) {
        minimum_index = i;

        for (int j = i + 1; j < vector_size; j++) {
            if ((*number_vector)[j] < (*number_vector)[minimum_index]) {
                minimum_index = j;
            }
        }

        if(minimum_index != i) {
            Swap(number_vector, minimum_index, i);
        }

        PerformScreenActions(number_vector, *screen, i, minimum_index);

        if (!(*visualizer_open_) || exit_prematurely_) {
            exit_prematurely_ = false;
            return false;
        }
    }
    return true;
}
