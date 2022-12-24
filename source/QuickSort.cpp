#include "../include/QuickSort.h"

int QuickSort::Partition(std::vector<int> *number_vector, int start, int end) {
    int pivot = (*number_vector)[end];

    int pivot_index = start;

    for (int i = start; i < end; i++) {
        if ((*number_vector)[i] <= pivot) {
            Swap(number_vector, pivot_index, i);
            pivot_index++;
        }
    }

    Swap(number_vector, pivot_index, end);

    return pivot_index;
}

void QuickSort::QuickSortRecursion(std::vector<int> *number_vector, Screen *screen, int start, int end) {
    if ((start < end) && *visualizer_open_ && !exit_prematurely_) {

        int pivot_index = Partition(number_vector, start, end);

        PerformScreenActions(number_vector, *screen, pivot_index);

        if (!(*visualizer_open_) || exit_prematurely_) {
            return;
        }

        QuickSortRecursion(number_vector, screen, start, pivot_index - 1);

        if (!(*visualizer_open_) || exit_prematurely_) {
            return;
        }

        QuickSortRecursion(number_vector, screen, pivot_index + 1, end);
    }
}

bool QuickSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();
    QuickSortRecursion(number_vector, screen, 0, vector_size - 1);

    if (exit_prematurely_) {
        exit_prematurely_ = false;
        return false;
    }

    return true;
}