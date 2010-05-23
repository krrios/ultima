#include "ultima.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void PrintHelp()
{
	std::cout << "usage: ultima (args...)\n\n";
	std::cout << "possible args:\n";
	std::cout << "  -fs     enable fullscreen mode\n";
	std::cout << "  -w W    set the client window width to W\n";
	std::cout << "  -h H    set the client window height to H\n";
	std::cout << "  -x X    set the leftmost side of the client to start at X\n";
	std::cout << "  -y Y    set the uppermost side of the client to start at Y\n";
}

int main(int argc, const char **argv)
{
	Configuration config;
	config.ParseArgs(argc, argv);

	if (config.print_help())
	{
		PrintHelp();
		return 0;
	}

	unsigned long style = sf::Style::Default;

	if (config.fullscreen())
	{
		style = sf::Style::Fullscreen;
	}

	sf::RenderWindow window(sf::VideoMode(config.screen_width(), config.screen_height()), "Ultima", style);
	window.SetPosition(config.screen_x(), config.screen_y());

	while (window.IsOpened())
	{
		sf::Event e;

		while (window.GetEvent(e))
		{
			if (e.Type == sf::Event::Closed || (e.Type == sf::Event::KeyPressed && e.Key.Code == sf::Key::Escape))
			{
				window.Close();
			}
		}
		
		window.Clear();
		window.Display();
	}

	return 0;
}