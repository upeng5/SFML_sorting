#include "sort_handler.h"

#include "sorting_algorithm.h"

SortHandler::SortHandler(const SortSettings& settings)
	: step_(1), settings_(settings)
{
}

SortHandler::SortHandler(const SortSettings& settings, size_t step_size)
	: settings_(settings), step_(step_size)
{
}

void SortHandler::SortStep(std::vector<RectangleShape>& bars, ALGORITHM algorithm)
{
	switch (algorithm)
	{
	case ALGORITHM::SELECTION_SORT:
		SelectionSortStep(bars, step_);
		break;
	case ALGORITHM::BUBBLE_SORT:
		BubbleSortStep(bars, step_);
		break;
	case ALGORITHM::MERGE_SORT:
		MergeSortStepIterative(bars, step_, settings_);
		break;
	case ALGORITHM::QUICK_SORT:
		QuickSortStep(bars, step_, quicksort_stack_);
		break;
	default:
		break;
	}

	step_++;
}

void SortHandler::Reset() {
	this->step_ = 1;
}