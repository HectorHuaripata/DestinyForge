#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "GameState.h"
#include "MainMenuState.h"

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization
	void initWindow();
	void initKeys(); 
	void initStates();

public:
	//Constructors & Destructors
	Game();
	virtual ~Game();

	//Functions
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};