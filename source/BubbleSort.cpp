#include "../include/BubbleSort.h"

bool BubbleSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();

    for (int i = 0; i < vector_size - 1; i++) {
        int num_1 = i;
        int num_2 = vector_size - 1;

        for (int j = 0; j < vector_size - i - 1; j++) {
            if ((*number_vector)[j] > (*number_vector)[j + 1]) {
                Swap(number_vector, j, j+1);
                num_2 = j;
            }
        }

        PerformScreenActions(number_vector, *screen, num_1, num_2);

        if (!(*visualizer_open_) || exit_prematurely_) {
            exit_prematurely_ = false;
            return false;
        }
    }
    return true;
}
