#include "RoundedRectangle.hpp"

RoundedRectangle::RoundedRectangle():height(0), width(0), radio(0){
	for (int i = 0; i < 4; i++)
	{
		roundedCorners[i] = sf::CircleShape(0);
	}
	backRectangle = sf::RectangleShape(sf::Vector2f(0, 0));
	foreRectangle = sf::RectangleShape(sf::Vector2f(0, 0));
}

RoundedRectangle::RoundedRectangle(float height, float width, float radio):height(height), width(width), radio(radio)
{
	for (int i = 0; i < 4; i++)
	{
		roundedCorners[i] = sf::CircleShape(radio);
	}
	
	backRectangle = sf::RectangleShape(sf::Vector2f(width - 2 * radio, height));
	foreRectangle = sf::RectangleShape(sf::Vector2f(width, height - 2 * radio));

	roundedCorners[0].setPosition(0, 0);
	roundedCorners[1].setPosition(0, height - 2 * radio);
	roundedCorners[2].setPosition(width - 2 * radio, height - 2 * radio);
	roundedCorners[3].setPosition(width - 2 * radio, 0);

	backRectangle.setPosition(radio, 0);
	foreRectangle.setPosition(0, radio);
}

void RoundedRectangle::setPosition(float x, float y)
{
	roundedCorners[0].setPosition(x, y);
	roundedCorners[1].setPosition(x, y + height - 2 * radio);
	roundedCorners[2].setPosition(x + width - 2 * radio,y + height - 2 * radio);
	roundedCorners[3].setPosition(x + width - 2 * radio, y);

	backRectangle.setPosition(x + radio, y);
	foreRectangle.setPosition(x, y + radio);
}

void RoundedRectangle::setFillColor(const sf::Color& color)
{
	roundedCorners[0].setFillColor(color);
	roundedCorners[1].setFillColor(color);
	roundedCorners[2].setFillColor(color);
	roundedCorners[3].setFillColor(color);

	backRectangle.setFillColor(color);
	foreRectangle.setFillColor(color);
}

void RoundedRectangle::move(float x, float y)
{
	roundedCorners[0].move(x,y);
	roundedCorners[1].move(x,y);
	roundedCorners[2].move(x,y);
	roundedCorners[3].move(x,y);

	backRectangle.move(x,y);
	foreRectangle.move(x,y);
}

void RoundedRectangle::draw(sf::RenderWindow& rwindow)
{
	rwindow.draw(roundedCorners[0]);
	rwindow.draw(roundedCorners[1]);
	rwindow.draw(roundedCorners[2]);
	rwindow.draw(roundedCorners[3]);

	rwindow.draw(backRectangle);
	rwindow.draw(foreRectangle);
}
