
#include "../include/SortingAlgorithm.h"

void SortingAlgorithm::HandleAlgorithmEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // Close the visualizer
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            *visualizer_open_ = false;
        }

        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
            exit_prematurely_ = true;
        }
    }
}

void SortingAlgorithm::Swap(std::vector<int> *number_vector, int index_1, int index_2) {
    int num_1 = (*number_vector)[index_1];
    int num_2 = (*number_vector)[index_2];
    (*number_vector)[index_2] = num_1;
    (*number_vector)[index_1] = num_2;
}

void SortingAlgorithm::PerformScreenActions(std::vector<int> *number_vector, Screen screen) {
    HandleAlgorithmEvents();
    screen.DrawFrame(*number_vector);
    Screen::Delay(VISUALIZER_DELAY);
}

void SortingAlgorithm::PerformScreenActions(std::vector<int> *number_vector, Screen screen, int x_highlight) {
    HandleAlgorithmEvents();
    screen.DrawFrame(*number_vector, x_highlight);
    Screen::Delay(VISUALIZER_DELAY);
}

void SortingAlgorithm::PerformScreenActions(std::vector<int> *number_vector, Screen screen, int x1_highlight, int x2_highlight) {
    HandleAlgorithmEvents();
    screen.DrawFrame(*number_vector, x1_highlight, x2_highlight);
}
