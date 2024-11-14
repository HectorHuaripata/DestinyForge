#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (!this->font1.loadFromFile("Fonts/Gabriola.ttf"))
		throw("There were problems loading the font...\n");
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string action = "";
		std::string key = "";
		while (ifs >> action >> key)
		{
			this->keybinds[action] = this->supportedKeys->at(key);
		}
	}
	ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();

	this->gamestate_btn = new Button(20, 20, 100, 40, &this->font1, "New Game", sf::Color::Yellow, sf::Color(255,255,0,255), sf::Color::Green);
	
	this->background.setSize(sf::Vector2f((float)window->getSize().x, (float)window->getSize().y));
	this->background.setFillColor(sf::Color::Cyan);
}

MainMenuState::~MainMenuState()
{
	delete this->gamestate_btn;
}

void MainMenuState::endState()
{
	std::cout << "Ending gameState!" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->background.move(1.0f, 0.0f);
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);


}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) target = this->window;

	target->draw(this->background);
}