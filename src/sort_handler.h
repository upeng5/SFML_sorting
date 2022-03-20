#ifndef SORT_HANDLER_H
#define SORT_HANDLER_H

#include <vector>
#include <stack>
#include <SFML/Graphics.hpp>

#include "sort_settings.h"

// Define sorting algorithm enums
enum class ALGORITHM {
	SELECTION_SORT,
	BUBBLE_SORT,
	MERGE_SORT,
	QUICK_SORT
};

class SortHandler {
public:
	SortHandler(const SortSettings& settings);
	SortHandler(const SortSettings& settings, size_t step_size);
	void SortStep(std::vector<sf::RectangleShape>& bars, ALGORITHM algorithm);
	void Reset();
private:
	size_t step_;
	SortSettings settings_;
	std::stack<int> quicksort_stack_;
};

#endif // !SORT_HANDLER_H
