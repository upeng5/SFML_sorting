#include <iostream>
#include <thread>
#include <chrono>

#include "utility.h"
#include "sort_handler.h"

#ifdef _DEBUG
#define LOG(x) std::cout << x << std::endl;
#endif // DEBUG

// CONSTANTS
const size_t kNumBars = 90;
const size_t kWindowWidth = 1200;
const size_t kWindowHeight = 800;
const float kXStartPos = 1.6f;

SortSettings settings{};

int main()
{
	sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight), "SFML Sorting Visualizer");

	// Get the window size
	sf::Vector2u window_size(window.getSize().x, window.getSize().y);

	// Normalize width to 1% of window width
	float shape_max_width = window_size.x * 0.01f;
	// Normalize height to 95% of window height
	float shape_max_height = window_size.y * 0.95f;

	// Define the increment
	float f_increment = shape_max_width + settings.margin;
	settings.increment = f_increment;

	std::vector<RectangleShape> bars = GenerateRandBars(kNumBars, shape_max_width, shape_max_height, window_size.x, settings);

	// Init sorting algorithm
	SortHandler handler(settings);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// window closed
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					// Reset bars
					bars = GenerateRandBars(kNumBars, shape_max_width, shape_max_height, window_size.x, settings);
					//step = 1;
					handler.Reset();
					break;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.close();
					break;
				}
				break;
			default:
				break;
			}
		}

		window.clear();

		// Sort here
		handler.SortStep(bars, ALGORITHM::BUBBLE_SORT);
		//
		// Render bars here
		for (const auto& bar : bars) {
			window.draw(bar);
		}

		window.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}

	return 0;
}