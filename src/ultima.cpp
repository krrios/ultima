#include "ultima.h"
#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ultima");

	while (window.IsOpened())
	{
		sf::Event e;

		while (window.GetEvent(e))
		{
			if (e.Type == sf::Event::Closed)
			{
				window.Close();
			}
		}
		
		window.Clear();
		window.Display();
	}

	return 0;
}