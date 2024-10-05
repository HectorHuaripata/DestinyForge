#include "MainMenu.h"

MainMenu::MainMenu() {
	if (!fntTitle.loadFromFile("Fonts/Gabriola.ttf"))
		std::cerr << "Error al cargar la fuente" << std::endl;

	//Opc New Game
	mainMenuOpc[0].setFont(fntTitle);
	mainMenuOpc[0].setString("Nuevo Juego");
	mainMenuOpc[0].setCharacterSize(40);
	mainMenuOpc[0].setFillColor(sf::Color::Black);
	mainMenuOpc[0].setPosition(30.0f, 380.0f);

	//Opc Continue
	mainMenuOpc[1].setFont(fntTitle);
	mainMenuOpc[1].setString("Continuar");
	mainMenuOpc[1].setCharacterSize(40);
	mainMenuOpc[1].setFillColor(sf::Color(0, 0, 0, 95));
	mainMenuOpc[1].setPosition(30.0f, 430.0f);

	//Opc Settings
	mainMenuOpc[2].setFont(fntTitle);
	mainMenuOpc[2].setString("Ajustes");
	mainMenuOpc[2].setCharacterSize(40);
	mainMenuOpc[2].setFillColor(sf::Color::Black);
	mainMenuOpc[2].setPosition(30.0f, 480.0f);

	//Opc Extra Content
	mainMenuOpc[3].setFont(fntTitle);
	mainMenuOpc[3].setString("Extra");
	mainMenuOpc[3].setCharacterSize(40);
	mainMenuOpc[3].setFillColor(sf::Color::Black);
	mainMenuOpc[3].setPosition(30.0f, 530.0f);

	//Selector
	selector = sf::VertexArray(sf::TriangleStrip, 4);
	// define it as a rectangle, located at (10, 10) and with size 100x100
	selector[0].position = sf::Vector2f(30.0f, 390.0f);//	s[0]				s[2]
	selector[1].position = sf::Vector2f(30.0f, 430.0f);
	selector[2].position = sf::Vector2f(230.0f, 390.0f);
	selector[3].position = sf::Vector2f(230.0f, 430.0f);//	s[1]				s[3]

	// define its texture area to be a 25x50 rectangle starting at (0, 0)
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);
	selector[2].color = sf::Color(255, 255, 255, 0);
	selector[3].color = sf::Color(255, 255, 255, 0);

	// Cargar una textura SFML
	if (!texture.loadFromFile("Textures/TitleScreenTexture.jpg")) {
		std::cerr << "Error al cargar la textura" << std::endl;
		// ...
	}

	sprite = sf::Sprite(texture);

	MainMenuSelected = 0;
}

MainMenu::~MainMenu(){}

void MainMenu::draw(sf::RenderWindow& rwindow) {
	rwindow.draw(sprite);
	rwindow.draw(selector, tSelector); 
	for (int i = 0; i < MAX_MAIN_MENU_OPTIONS; ++i) {
		rwindow.draw(mainMenuOpc[i]);
	}	
}

void MainMenu::moveUp()
{
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);
	if (MainMenuSelected - 1 >= 0)
	{
		tSelector.translate(0.0f, -50.0f);
		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
			tSelector.translate(0.0f, 150.0f);
		}
	}
}

void MainMenu::moveDown()
{
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);

	if (MainMenuSelected + 1 < MAX_MAIN_MENU_OPTIONS)
	{
		tSelector.translate(0.0f, 50.0f);
		MainMenuSelected++;
		if (MainMenuSelected == MAX_MAIN_MENU_OPTIONS)
		{
			MainMenuSelected = 0;
			tSelector.translate(0.0f, 150.0f);
		}
	}
}

void MainMenu::update()
{
	//switch (MainMenuSelected)
	//{
	//case 0:
	//	//TODO: Encontrar la manera de cambiar el gameState del GM sin llamarlo
	//	//GM.ChangeGameState(GameState::BATTLE);
	//	std::cout << "Deberia iniciar el combate..." << std::endl;
	//	break;
	//case 1:
	//	std::cout << "No tienes partida guardada." << std::endl;
	//	break;
	//case 2:
	//	std::cout << "No hay ajustes aun" << std::endl;
	//	break;
	//case 3:
	//	std::cout << "Aun estoy desarrollando el contenido extra" << std::endl;
	//	break;

	//default:
	//	std::cout << "Informanos como llegaste aqui... por favor" << std::endl;
	//	break;
	//}
}
