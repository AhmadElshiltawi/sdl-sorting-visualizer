#include "../include/RadixSort.h"

bool RadixSort::Sort(std::vector<int> *number_vector, Screen *screen) {
    int vector_size = (int) (*number_vector).size();

    int biggest_element = *max_element(number_vector->begin(), number_vector->end());

    int number_of_parses = number_of_digits(biggest_element);

    for (int parse_count = 0; parse_count < number_of_parses; parse_count++) {

        for (int i = 0; i < vector_size; i++) {
            bucket_[digit_at_position((*number_vector)[i], parse_count)].push_back((*number_vector)[i]);
        }

        int vector_index = 0;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < (int) bucket_[i].size(); j++) {
                (*number_vector)[vector_index] = bucket_[i][j];
                vector_index++;

                if ((j % 10) == 0) {
                    PerformScreenActions(number_vector, *screen);

                    if (!(*visualizer_open_) || exit_prematurely_) {
                        ClearBucket();
                        exit_prematurely_ = false;
                        return false;
                    }
                }
            }
        }
        ClearBucket();
    }

    return true;
}

int RadixSort::number_of_digits(int number) {
    if (number <= 0) {
        return 1;
    }
    else {
        return (int) log10 (number) + 1;
    }
}

int RadixSort::digit_at_position(int number, int position) {
    int number_to_divide = (int) pow(10, position);

    return  ((number / number_to_divide) % 10);
}

void RadixSort::ClearBucket() {
    for (auto & vector : bucket_) {
        vector.clear();
    }
}
