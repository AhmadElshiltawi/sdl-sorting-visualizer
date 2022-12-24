#include "../include/MergeSort.h"

bool MergeSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();
    MergeSortRecursion(number_vector, screen, 0, vector_size - 1);

    if (exit_prematurely_) {
        exit_prematurely_ = false;
        return false;
    }

    return true;
}

void MergeSort::MergeSortRecursion(std::vector<int> *number_vector, Screen *screen, int start, int end) {
    int mid_point = start + (end - start) / 2;

    if (start < end && (*visualizer_open_) && !exit_prematurely_) {
        MergeSortRecursion(number_vector, screen, start, mid_point);

        if (!(*visualizer_open_) || exit_prematurely_) {
            return;
        }

        MergeSortRecursion(number_vector, screen, mid_point + 1, end);

        if (!(*visualizer_open_) || exit_prematurely_) {
            return;
        }

        Merge(number_vector, start, mid_point, end);

        PerformScreenActions(number_vector, *screen, start, end);
    }
}

void MergeSort::Merge(std::vector<int> *number_vector, int start, int mid, int end) {
    int left_size = mid - start + 1;
    int right_size = end - mid;

    int left_array[left_size];
    int right_array[right_size];

    for (int i = 0; i < left_size; i++) {
        left_array[i] = (*number_vector)[start + i];
    }

    for (int i = 0; i < right_size; i++) {
        right_array[i] = (*number_vector)[mid + i + 1];
    }

    int number_vector_index = start;
    int left_array_index = 0;
    int right_array_index = 0;

    for (; number_vector_index <= end; number_vector_index++) {
        if ((left_array_index < left_size)
        && (right_array_index >= right_size || left_array[left_array_index] <= right_array[right_array_index])) {
            (*number_vector)[number_vector_index] = left_array[left_array_index];
            left_array_index++;
        }
        else {
            (*number_vector)[number_vector_index] = right_array[right_array_index];
            right_array_index++;
        }
    }
}