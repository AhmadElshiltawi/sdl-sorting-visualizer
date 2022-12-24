
#ifndef SORTING_VISUALIZER_H
#define SORTING_VISUALIZER_H

#include "Screen.h"
#include "NumberGenerator.h"
#include "Common.h"
#include "SortingStrategy.h"

#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "BogusSort.h"
#include "CocktailSort.h"
#include "ShellSort.h"
#include "RadixSort.h"

#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

class Visualizer {
private:
    bool visualizer_open_ = true;

    bool verification_in_progress = false;
    int current_verification_index = 0;

    SortingAlgorithms current_algorithm_ = NONE;
    std::vector<int> number_vector_;
    NumberGenerator &number_generator_;

    Screen screen_;

    SortingStrategy sorting_strategy_;

    BubbleSort bubble_sort_;
    SelectionSort selection_sort_;
    InsertionSort insertion_sort_;
    QuickSort quick_sort_;
    MergeSort merge_sort_;
    BogusSort bogus_sort_;
    CocktailSort cocktail_sort_;
    ShellSort shell_sort_;
    RadixSort radix_sort_;


    void HandleNewChoiceEvent();
    void PopulateVector();

public:
    Visualizer() : number_generator_(NumberGenerator::GetInstance()),
                   sorting_strategy_(&number_vector_, &screen_),
                   bubble_sort_(&visualizer_open_),
                   selection_sort_(&visualizer_open_),
                   insertion_sort_(&visualizer_open_),
                   quick_sort_(&visualizer_open_),
                   merge_sort_(&visualizer_open_),
                   bogus_sort_(&visualizer_open_, &number_generator_),
                   cocktail_sort_(&visualizer_open_),
                   shell_sort_(&visualizer_open_),
                   radix_sort_(&visualizer_open_) {};

    void Run();

    std::string AlgorithmToString();
};


#endif
