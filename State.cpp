#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys): window(window), quit(false), supportedKeys(supportedKeys)
{
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		this->quit = true;
	}
}

void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords( sf::Mouse::getPosition(*this->window));
}
