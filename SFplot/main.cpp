#include <complex>
#include <iostream>

#include <SFML/Graphics.hpp>

int MandelbrotConverge(std::complex<float> c, std::size_t n)
{
	std::complex<float> z = c;
	for (std::size_t i = 0; i < n; i++)
	{
		z = z * z + c;
		if (z.real() * z.real() + z.imag() * z.imag() > 2 * 2)
		{
			return i;
		}
	}
	return -1;
}

void CalculateMandelbrot(std::size_t width, std::size_t height, std::size_t n, int x_move, int y_move, std::size_t zoom, sf::VertexArray& v_arr)
{
	for (float x = 0; x < width; x++)
	{
		for (float y = 0; y < height; y++)
		{
			int result = MandelbrotConverge(std::complex<float>((x - width / 2 + x_move) / zoom, (y - height / 2 + y_move) / zoom), n);
			sf::Vertex point({ x, y });


			if (result != -1)
			{
				int exp = std::pow(result, 2);
				point.color = sf::Color(exp, exp, exp);

			}
			v_arr.append(point);
		}
	}
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Mandelbrot");

	sf::VertexArray va;

	int n = 1000, x_move = 0, y_move = 0;
	std::size_t zoom = 100;
	CalculateMandelbrot(window.getSize().x, window.getSize().y, n, x_move, y_move, zoom, va);
	
	int move_distance = 100;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					x_move -= move_distance;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					x_move += move_distance;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					y_move -= move_distance;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					y_move += move_distance;
				}
				else
				{
					zoom += 100;
				}

				CalculateMandelbrot(window.getSize().x, window.getSize().y, n, x_move, y_move, zoom, va);
			}
		}

		window.clear(/*sf::Color::White*/);
		window.draw(va);
		window.display();
	}

	return 0;
}