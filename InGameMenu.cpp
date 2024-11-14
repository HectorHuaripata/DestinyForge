#include "InGameMenu.h"

InGameMenu::InGameMenu()
{
	if (!fntTitle.loadFromFile("Fonts/Gabriola.ttf"))
		std::cerr << "Error al cargar la fuente" << std::endl;

	//Opc Party
	ingameMenuOpc[0].setFont(fntTitle);
	ingameMenuOpc[0].setString("Grupo");
	ingameMenuOpc[0].setCharacterSize(30);
	ingameMenuOpc[0].setFillColor(sf::Color::Black);
	ingameMenuOpc[0].setPosition(15.0f, 20.0f);

	//Opc Ability
	ingameMenuOpc[1].setFont(fntTitle);
	ingameMenuOpc[1].setString("Habilidad");
	ingameMenuOpc[1].setCharacterSize(30);
	ingameMenuOpc[1].setFillColor(sf::Color::Black);
	ingameMenuOpc[1].setPosition(15.0f, 70.0f);

	//Opc Inventory
	ingameMenuOpc[2].setFont(fntTitle);
	ingameMenuOpc[2].setString("Inventario");
	ingameMenuOpc[2].setCharacterSize(30);
	ingameMenuOpc[2].setFillColor(sf::Color::Black);
	ingameMenuOpc[2].setPosition(15.0f, 120.0f);

	//Opc Equip
	ingameMenuOpc[3].setFont(fntTitle);
	ingameMenuOpc[3].setString("Equipo");
	ingameMenuOpc[3].setCharacterSize(30);
	ingameMenuOpc[3].setFillColor(sf::Color::Black);
	ingameMenuOpc[3].setPosition(15.0f, 170.0f);

	//Opc Map
	ingameMenuOpc[4].setFont(fntTitle);
	ingameMenuOpc[4].setString("Mapa");
	ingameMenuOpc[4].setCharacterSize(30);
	ingameMenuOpc[4].setFillColor(sf::Color::Black);
	ingameMenuOpc[4].setPosition(15.0f, 220.0f);

	//Opc Save
	ingameMenuOpc[5].setFont(fntTitle);
	ingameMenuOpc[5].setString("Guardar");
	ingameMenuOpc[5].setCharacterSize(30);
	ingameMenuOpc[5].setFillColor(sf::Color::Black);
	ingameMenuOpc[5].setPosition(15.0f, 270.0f);

	//Opc Settings
	ingameMenuOpc[6].setFont(fntTitle);
	ingameMenuOpc[6].setString("Ajustes");
	ingameMenuOpc[6].setCharacterSize(30);
	ingameMenuOpc[6].setFillColor(sf::Color::Black);
	ingameMenuOpc[6].setPosition(15.0f, 320.0f);


	//Selector
	selector = sf::VertexArray(sf::TriangleStrip, 4);
	// define it as a rectangle, located at (10, 10) and with size 100x100
	selector[0].position = sf::Vector2f(10.0f, 25.0f);//	s[0]				s[2]
	selector[1].position = sf::Vector2f(10.0f, 65.0f);
	selector[2].position = sf::Vector2f(200.0f, 25.0f);
	selector[3].position = sf::Vector2f(200.0f, 65.0f);//	s[1]				s[3]

	// define its texture area to be a 25x50 rectangle starting at (0, 0)
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);
	selector[2].color = sf::Color(255, 255, 255, 0);
	selector[3].color = sf::Color(255, 255, 255, 0);

	// Cargar una textura SFML
	if (!txtrCoin.loadFromFile("Textures/coin_icon.png")) {
		std::cerr << "Error al cargar la textura" << std::endl;
		// ...
	}

	sptCoin = sf::Sprite(txtrCoin);
	sptCoin.move(750.0f, 550.0f);

	menuOpcSelected = 0;
}

void InGameMenu::draw(sf::RenderWindow& rwindow)
{
	rwindow.draw(sptCoin);
	rwindow.draw(selector, tSelector);
	for (int i = 0; i < MAX_INGAME_MENU_OPTIONS; ++i) {
		rwindow.draw(ingameMenuOpc[i]);
	}
}

void InGameMenu::moveUp()
{
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);
	if (menuOpcSelected - 1 >= 0)
	{
		tSelector.translate(0.0f, -50.0f);
		menuOpcSelected--;
		if (menuOpcSelected == -1)
		{
			menuOpcSelected = 2;
			tSelector.translate(0.0f, 150.0f);
		}
	}
}

void InGameMenu::moveDown()
{
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);

	if (menuOpcSelected + 1 < MAX_INGAME_MENU_OPTIONS)
	{
		tSelector.translate(0.0f, 50.0f);
		menuOpcSelected++;
		if (menuOpcSelected == MAX_INGAME_MENU_OPTIONS)
		{
			menuOpcSelected = 0;
			tSelector.translate(0.0f, 150.0f);
		}
	}
}

void InGameMenu::update()
{
	selector[0].color = sf::Color(0, 127, 255, 255);
	selector[1].color = sf::Color(0, 127, 255, 255);
}

InGameMenu::~InGameMenu(){}
