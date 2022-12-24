
#ifndef SORTING_VISUALIZER_NUMBER_GENERATOR_H
#define SORTING_VISUALIZER_NUMBER_GENERATOR_H

#include "Common.h"
#include <random>
#include <algorithm>

class NumberGenerator {
private:
    std::random_device rd;
    std::uniform_int_distribution<> dist;

    NumberGenerator() : dist(MINIMUM_RANGE, MAXIMUM_RANGE) {};

public:
    NumberGenerator(NumberGenerator const& copy) = delete;
    void operator=(NumberGenerator const& rhs) = delete;
    static NumberGenerator& GetInstance();
    int GenerateNumber();
    void ShuffleVector(std::vector<int> *number_vector);
};


#endif
