#include "../include/NumberGenerator.h"

NumberGenerator &NumberGenerator::GetInstance() {
    static NumberGenerator instance_;
    return instance_;
}

int NumberGenerator::GenerateNumber() {
    return dist(rd);
}

void NumberGenerator::ShuffleVector(std::vector<int> *number_vector) {
    std::shuffle(std::begin(*number_vector), std::end(*number_vector), rd);
}
