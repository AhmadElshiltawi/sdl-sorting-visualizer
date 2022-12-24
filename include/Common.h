
#ifndef SORTING_VISUALIZER_COMMON_H
#define SORTING_VISUALIZER_COMMON_H

#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_ttf.h>

const int BAR_WIDTH = 1;

const int VECTOR_SIZE = 1000;

const int MINIMUM_RANGE = 1;
const int MAXIMUM_RANGE = 1000;

const int VISUALIZER_DELAY = 50;

const int SKIP_FRAMES = 5;

enum SortingAlgorithms {
    BUBBLE_SORT,
    INSERTION_SORT,
    QUICK_SORT,
    SELECTION_SORT,
    MERGE_SORT,
    BOGUS_SORT,
    COCKTAIL_SORT,
    SHELL_SORT,
    RADIX_SORT,
    NONE
};

struct Dimension {
    int width, length;
};

struct Colour {
    int r, g, b;
};

#endif
