#pragma once
#include <SFML/Graphics.hpp>

class RoundedRectangle {
private:
	sf::RectangleShape backRectangle, foreRectangle;
	sf::CircleShape roundedCorners[4];
	float height, width, radio;

public:
	RoundedRectangle();
	RoundedRectangle(float height, float width, float radio);
	void setPosition(float x, float y);
	void setFillColor(const sf::Color &color);
	void move(float x, float y);
	void draw(sf::RenderWindow& rwindow);

};