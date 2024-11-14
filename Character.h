#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Character
{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed = 500.0f;

public:
	Character();
	virtual ~Character();

	//Functions
	void move(const float &dt, const float x, const float y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

