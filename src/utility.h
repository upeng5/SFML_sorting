#ifndef UTILITY_H
#define UTILITY_H

// Common headers & libs
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

#include "sort_settings.h"

using sf::RectangleShape;
using sf::Color;

inline float RandomFloat();

inline float RandomFloat(float min, float max);

void Exch(std::vector<RectangleShape>& bars, size_t i, size_t j);

void SetBar(std::vector<RectangleShape>& bars, size_t i, const RectangleShape& bar, float x_pos);

std::vector<RectangleShape> GenerateRandBars(size_t num, float max_width, float max_height, size_t window_width, const SortSettings& settings);

std::vector<RectangleShape> GenerateBars(size_t num, float max_width, float max_height, size_t window_width, float margin, const SortSettings& settings);

void ColorBars(std::vector<RectangleShape>& bars, size_t begin, size_t end, Color color);

#endif // !UTILITY_H
