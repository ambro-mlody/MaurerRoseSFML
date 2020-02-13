#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include<math.h>
#define W 800
#define H 600

float degreesToRadians(float angle)
{
	return angle * M_PI / 180;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(W, H), "Maurer Rose");
	window.setFramerateLimit(60);

	float xoff = W / 2;
	float yoff = H / 2;
	sf::VertexArray shape(sf::PrimitiveType::LinesStrip, 361);
	sf::VertexArray base(sf::PrimitiveType::LinesStrip, 361);
	float n = 0;
	float d = 0;
	

	while (window.isOpen())
	{
		n += 0.01;
		d += 0.03;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		for (int i = 0; i < 361; i++)
		{
			float k = i * d;
			float r = 150 * sin(degreesToRadians(n * k));
			float x = r * cos(degreesToRadians(k)) + xoff;
			float y = r * sin(degreesToRadians(k)) + yoff;

			shape[i].position = { x, y };
			shape[i].color = sf::Color::Blue;
		}

		for (int i = 0; i < 361; i++)
		{
			float k = i;
			float r = 150 * sin(degreesToRadians(n * k));
			float x = r * cos(degreesToRadians(k)) + xoff;
			float y = r * sin(degreesToRadians(k)) + yoff;

			base[i].position = { x, y };
			base[i].color = sf::Color::Red;
		}
		window.clear();
		
		window.draw(shape);
		window.draw(base);

		window.display();
	}

	return 0;
}