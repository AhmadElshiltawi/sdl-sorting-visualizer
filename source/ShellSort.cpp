#include "../include/ShellSort.h"

bool ShellSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();

    for (int gap = vector_size/2; gap > 0; gap /= 2) {

        for (int i = gap; i < vector_size; i++) {
            int item = (*number_vector)[i];

            int j;

            for (j = i; j >= gap && (*number_vector)[j - gap] > item; j -= gap) {
                (*number_vector)[j] = (*number_vector)[j - gap];
            }

            (*number_vector)[j] = item;

            if ((i % 4) == 0) {
                PerformScreenActions(number_vector, *screen, i, j);

                if (!(*visualizer_open_) || exit_prematurely_) {
                    exit_prematurely_ = false;
                    return false;
                }
            }
        }
    }

    return true;
}
