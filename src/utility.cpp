#include "utility.h"

inline float RandomFloat() {
	// Returns a random real in [0,1).
	return rand() / (RAND_MAX + 1.0);
}

inline float RandomFloat(float min, float max) {
	// Returns a random real in [min,max).
	return min + (max - min) * RandomFloat();
}

void Exch(std::vector<RectangleShape>& bars, size_t i, size_t j) {
	// Get the positions
	sf::Vector2f temp_pos(bars[i].getPosition());

	// Highlight selection
	bars[i].setFillColor(Color::Green);
	bars[j].setFillColor(Color::Green);

	bars[i].setPosition(bars[j].getPosition());
	bars[j].setPosition(temp_pos);

	sf::RectangleShape temp = bars[i];
	bars[i] = bars[j];
	bars[j] = temp;
}

void SetBar(std::vector<RectangleShape>& bars, size_t i, const RectangleShape& bar, float x_pos) {
	//sf::Vector2f pos = bar.getPosition();

	// Highlight selection
	bars[i] = bar;
	bars[i].setPosition(x_pos, 0);
	bars[i].setFillColor(Color::Green);
	//bars[i] = bar;
}

std::vector<RectangleShape> GenerateRandBars(size_t num, float max_width, float max_height, size_t window_width, const SortSettings& settings) {
	std::vector<RectangleShape> bars(num);
	float curr_height, curr_pos_x = settings.start_pos;
	float increment = max_width + settings.margin;
	for (size_t i = 0; i < num; i++)
	{
		// To prevent rendering bars that extend beyond the window width
		if (curr_pos_x >= window_width) {
			break;
		}
		// Min height = 5.f
		curr_height = RandomFloat(5.f, max_height - 1);
		RectangleShape bar(sf::Vector2f(max_width, curr_height));
		bar.setPosition(sf::Vector2f(curr_pos_x, 0.f));
		bar.setFillColor(sf::Color::Red);
		bars[i] = bar;
		curr_pos_x += increment;
	}

	return bars;
}

std::vector<RectangleShape> GenerateBars(size_t num, float max_width, float max_height, size_t window_width, float margin, const SortSettings& settings) {
	std::vector<RectangleShape> bars(num);
	float curr_height = 500.f, curr_pos_x = settings.start_pos;
	float increment = max_width + settings.margin;
	for (size_t i = 0; i < num; i++)
	{
		// To prevent rendering bars that extend beyond the window width
		if (curr_pos_x >= window_width) {
			break;
		}
		// Min height = 5.f
		curr_height -= 20.f;
		RectangleShape bar(sf::Vector2f(max_width, curr_height));
		bar.setPosition(sf::Vector2f(curr_pos_x, 0.f));
		bar.setFillColor(sf::Color::Red);
		bars[i] = bar;
		curr_pos_x += increment;
	}

	return bars;
}

void ColorBars(std::vector<RectangleShape>& bars, size_t begin, size_t end, Color color)
{
	if (begin >= end) return;

	for (size_t i = begin; i < end; i++)
	{
		bars[i].setFillColor(color);
	}
}