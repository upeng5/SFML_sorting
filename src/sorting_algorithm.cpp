#include "sorting_algorithm.h"

#include <iostream>
#include <algorithm>

void Merge(std::vector<RectangleShape>& bars, std::vector<RectangleShape>& aux, int left, int mid, int right, const SortSettings& settings) {
	aux.reserve(bars.size());

	// Copy to aux
	for (int k = left; k <= right; k++) {
		aux[k] = bars[k];
	}

	// Get the start and increment
	float curr_x = settings.start_pos;
	float increment = settings.increment;

	// Merge back to bars
	int i = left, j = mid + 1;
	for (int k = left; k <= right; k++)
	{
		if (i > mid) {
			SetBar(bars, k, aux[j++], curr_x);
			curr_x += increment;
		}
		else if (j > right) {
			SetBar(bars, k, aux[i++], curr_x);
			curr_x += increment;
		}
		else if (bars[j].getSize().y <= bars[i].getSize().y) {
			SetBar(bars, k, aux[j++], curr_x);
			curr_x += increment;
		}
		else {
			SetBar(bars, k, aux[i++], curr_x);
			curr_x += increment;
		}
	}
}

int Partition(std::vector<RectangleShape>& bars, int lo, int hi, size_t step) {
	int i = lo;
	int j = hi + 1;

	if (step >= bars.size()) {
	}

	RectangleShape pivot = bars[lo];
	for (size_t k = 0; k <= step; k++) {
		// find item on lo to swap
		while (bars[++i].getSize().y <= pivot.getSize().y) {
			if (i == hi) break;
		}

		// find item on hi to swap
		while (bars[--j].getSize().y > pivot.getSize().y) {
			if (j == lo) break;      // redundant since a[lo] acts as sentinel
		}

		// check if pointers cross
		if (i >= j) break;

		Exch(bars, i, j);
	}

	// put partitioning item pivot at bars[j]
	Exch(bars, lo, j);

	return j;
}

// #### SORTING FUNCTIONS ####
void SelectionSortStep(std::vector<RectangleShape>& bars, size_t step) {
	if (step >= bars.size()) return;

	int min_idx;
	for (size_t i = 0; i < step; i++)
	{
		min_idx = i;
		for (size_t j = i + 1; j < bars.size(); j++)
		{
			if (bars[j].getSize().y < bars[min_idx].getSize().y) {
				min_idx = j;
			}
		}
		Exch(bars, i, min_idx);
	}
}

void BubbleSortStep(std::vector<RectangleShape>& bars, size_t step) {
	if (step >= bars.size()) return;

	for (int i = 0; i < step; i++) {
		for (int j = 0; j < step - i; ++j) {
			if (bars[j].getSize().y > bars[j + 1].getSize().y) {
				Exch(bars, j + 1, j);
			}
		}
	}
	bars[0].setFillColor(Color::Green);
}

void MergeSortStepIterative(std::vector<RectangleShape>& bars, size_t step, const SortSettings& settings)
{
	if (step >= bars.size()) return;

	int n = bars.size();
	std::vector<RectangleShape> aux(bars.size());
	for (int len = 1; len < step; len *= 2) {
		for (int lo = 0; lo < n - len; lo += len + len) {
			int mid = lo + len - 1;
			int hi = std::min(lo + len + len - 1, n - 1);
			Merge(bars, aux, lo, mid, hi, settings);
		}
	}
}

void QuickSortStep(std::vector<RectangleShape>& bars, size_t step, std::stack<int>& aux_stack) {
	if (step > bars.size()) return;

	int l, h;
	// Create an auxiliary stack
	if (step == 1) {
		// initialize top of stack
		aux_stack.push(-1);

		// push the start and end
		aux_stack.push(0);
		aux_stack.push(bars.size() - 1);
	}

	// Keep popping from stack if it is not empty
	if (aux_stack.top() >= 0) {
		// Pop h and l
		h = aux_stack.top();
		aux_stack.pop();
		l = aux_stack.top();
		aux_stack.pop();

		// Set pivot element at its correct position
		// in sorted array
		int p = Partition(bars, l, h, step);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > l) {
			aux_stack.push(1);
			aux_stack.push(p - 1);
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < h) {
			aux_stack.push(p + 1);
			aux_stack.push(h);
		}
	}
}