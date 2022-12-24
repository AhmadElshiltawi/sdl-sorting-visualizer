
#include "../include/InsertionSort.h"

bool InsertionSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();

    for (int i = 1; i < vector_size; i++) {
        int item = (*number_vector)[i];

        int j = i - 1;
        while (j >= 0 && (*number_vector)[j] > item) {
            (*number_vector)[j + 1] = (*number_vector)[j];
            j = j - 1;
        }

        (*number_vector)[j + 1] = item;

        PerformScreenActions(number_vector, *screen, i, j);

        if (!(*visualizer_open_) || exit_prematurely_) {
            exit_prematurely_ = false;
            return false;
        }
    }
    return true;
}
