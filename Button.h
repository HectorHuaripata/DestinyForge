#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum button_states{ BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
private:
	unsigned int buttonstate;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;

public:
	Button(float x, float y, float width, float height,
		   sf::Font* font ,std::string text,
		   sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor);
	~Button();

	const bool getState() const { return this->buttonstate;	}

	//Functions
	void update(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

