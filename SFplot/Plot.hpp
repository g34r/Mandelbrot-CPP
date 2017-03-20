#pragma once
#include <string>

#include <SFML/Graphics.hpp>

namespace SFplot
{
	class Plot
	{
	private:
		sf::Vector2u m_size;

		sf::Vector2i m_origin { 0, 0 };
		double m_axis_number_distance { 1.0 };
	public:
		Plot(sf::Vector2i size) : m_size(size)
		{

		}

		void setSize(sf::Vector2u size)
		{
			m_size = size;
		}

		void setOrigin(sf::Vector2i origin) 
		{ 
			m_origin = origin; 
		}

		void drawAxis(sf::Color color, sf::RenderWindow& window)
		{
			sf::VertexArray x_axis;
			x_axis[0] = sf::Vector2f(0, m_origin.y);
			x_axis[0].color = color;
			x_axis[1] = sf::Vector2f(m_size.x, m_origin.y);
			x_axis[1].color = color;

			window.draw(x_axis);

			sf::VertexArray y_axis;
			y_axis[0] = sf::Vector2f(m_origin.x, 0);
			y_axis[0].color = color;
			y_axis[1] = sf::Vector2f(m_origin.x, m_size.y);
			y_axis[1].color = color;

			window.draw(y_axis);
		}

		void drawAxisNumber(sf::Color color, sf::Font font, unsigned int font_size, sf::RenderWindow& window)
		{
			for (float x_pos = m_origin.x; x_pos < m_size.x; x_pos += m_axis_number_distance)
			{

			}
		}
	};
}