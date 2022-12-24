#include "../include/Visualizer.h"

void Visualizer::Run() {
    PopulateVector();

    while (visualizer_open_) {
        HandleNewChoiceEvent();

        if (current_algorithm_ != NONE) {

            current_verification_index = 0;
            verification_in_progress = false;

            std::cout << "Current algorithm running: " << AlgorithmToString() << "." << std::endl;

            auto start = Clock::now();

            bool finished_sorting = sorting_strategy_.Sort();

            auto end = Clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

            std::cout << AlgorithmToString() << " finished sorting in: " << duration << " seconds." << std::endl << std::endl;

            sorting_strategy_.SetStrategy(nullptr);
            current_algorithm_ = NONE;

            if (finished_sorting) {
                verification_in_progress = true;
            }
        }
        else {
            if (verification_in_progress) {
                if (current_verification_index == number_vector_.size() - 1 || (number_vector_[current_verification_index] <= number_vector_[current_verification_index + 1])) {
                    screen_.DrawVerificationFrame(number_vector_, current_verification_index);

                    if (current_verification_index == number_vector_.size() - 1) {
                        Screen::Delay(VISUALIZER_DELAY);
                        current_verification_index = 0;
                        verification_in_progress = false;
                    }
                }
                else {
                    screen_.DrawFrame(number_vector_, current_verification_index);
                    current_verification_index = 0;
                    verification_in_progress = false;
                    Screen::Delay(VISUALIZER_DELAY * 10);
                }

                current_verification_index++;
            }
            else {
                screen_.DrawFrame(number_vector_);
                Screen::Delay(VISUALIZER_DELAY);
            }
        }
    }
}

void Visualizer::HandleNewChoiceEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            visualizer_open_ = false;
        }

        if (event.type == SDL_KEYDOWN && current_algorithm_ == NONE) {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE: {
                    PopulateVector();
                    current_verification_index = 0;
                    verification_in_progress = false;
                    break;
                }
                case SDLK_1: {
                    sorting_strategy_.SetStrategy(&bubble_sort_);
                    current_algorithm_ = BUBBLE_SORT;
                    break;
                }
                case SDLK_2: {
                    sorting_strategy_.SetStrategy(&selection_sort_);
                    current_algorithm_ = SELECTION_SORT;
                    break;
                }
                case SDLK_3: {
                    sorting_strategy_.SetStrategy(&insertion_sort_);
                    current_algorithm_ = INSERTION_SORT;
                    break;
                }
                case SDLK_4: {
                    sorting_strategy_.SetStrategy(&quick_sort_);
                    current_algorithm_ = QUICK_SORT;
                    break;
                }
                case SDLK_5: {
                    sorting_strategy_.SetStrategy(&merge_sort_);
                    current_algorithm_ = MERGE_SORT;
                    break;
                }
                case SDLK_6: {
                    sorting_strategy_.SetStrategy(&cocktail_sort_);
                    current_algorithm_ = COCKTAIL_SORT;
                    break;
                }
                case SDLK_7: {
                    sorting_strategy_.SetStrategy(&shell_sort_);
                    current_algorithm_ = SHELL_SORT;
                    break;
                }
                case SDLK_8: {
                    sorting_strategy_.SetStrategy(&radix_sort_);
                    current_algorithm_ = RADIX_SORT;
                    break;
                }
                case SDLK_9: {
                    sorting_strategy_.SetStrategy(&bogus_sort_);
                    current_algorithm_ = BOGUS_SORT;
                    break;
                }
            }
        }
    }
}

void Visualizer::PopulateVector() {
    number_vector_.clear();

    for (int i = 0; i < VECTOR_SIZE; i++) {
        number_vector_.push_back(number_generator_.GenerateNumber());
    }
}

std::string Visualizer::AlgorithmToString() {
    switch (current_algorithm_) {
        case NONE:
            return "None";
        case BUBBLE_SORT:
            return "Bubble Sort";
        case INSERTION_SORT:
            return "Insertion Sort";
        case SELECTION_SORT:
            return "Selection Sort";
        case QUICK_SORT:
            return "Quick Sort";
        case MERGE_SORT:
            return "Merge Sort";
        case BOGUS_SORT:
            return "Bogus Sort";
        case COCKTAIL_SORT:
            return "Cocktail Sort";
        case SHELL_SORT:
            return "Shell Sort";
        case RADIX_SORT:
            return "Radix Sort";
    }
}
