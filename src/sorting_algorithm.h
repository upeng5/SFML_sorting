#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include "utility.h"
#include "sort_settings.h"

// HELPERS
void Merge(std::vector<RectangleShape>& bars, std::vector<RectangleShape>& aux, int left, int mid, int right, const SortSettings& settings);

int Partition(std::vector<RectangleShape>& bars, int lo, int hi, size_t step);

// #### SORTING FUNCTIONS ####
void SelectionSortStep(std::vector<RectangleShape>& bars, size_t step);

void BubbleSortStep(std::vector<RectangleShape>& bars, size_t step);

void MergeSortStepIterative(std::vector<RectangleShape>& bars, size_t step, const SortSettings& settings);

void QuickSortStep(std::vector<RectangleShape>& bars, size_t step, std::stack<int>& aux_stack);

#endif