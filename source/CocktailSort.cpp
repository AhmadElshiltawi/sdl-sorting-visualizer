#include "../include/CocktailSort.h"

bool CocktailSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();

    bool swap_performed = true;

    int start = 0;
    int end = vector_size - 1;

    int left_right_index = 0;
    int right_left_index = 0;

    while (swap_performed) {

        // ---- Start of left to right bubble sort --- //

        swap_performed = false;

        for (int i = start; i < end; i++) {
            if ((*number_vector)[i] > (*number_vector)[i + 1]) {
                Swap(number_vector, i, i + 1);
                left_right_index = i;
                swap_performed = true;
            }
        }

        if (!swap_performed) {
            return true;
        }

        end--;

        // ---- end of left to right bubble sort --- //

        PerformScreenActions(number_vector, *screen, left_right_index, right_left_index);

        if (!(*visualizer_open_) || exit_prematurely_) {
            exit_prematurely_ = false;
            return false;
        }

        // ---- Start of right to left bubble sort --- //

        swap_performed = false;

        for (int i = end - 1; i >= start; i--) {
            if ((*number_vector)[i] > (*number_vector)[i + 1]) {
                Swap(number_vector, i, i + 1);
                right_left_index = i;
                swap_performed = true;
            }
        }

        if (!swap_performed) {
            return true;
        }

        start++;

        // ---- end of right to left bubble sort --- //

        PerformScreenActions(number_vector, *screen, left_right_index, right_left_index);

        if (!(*visualizer_open_) || exit_prematurely_) {
            exit_prematurely_ = false;
            return false;
        }
    }

    return true;
}
