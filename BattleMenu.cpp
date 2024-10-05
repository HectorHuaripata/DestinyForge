#include "BattleMenu.hpp"
#include "GameManager.hpp"

BattleMenu::BattleMenu()
{
	if (!fntTitle.loadFromFile("Fonts/Gabriola.ttf"))
		std::cerr << "Error al cargar la fuente" << std::endl;

	//Base Rectangle
	baseRectangle = RoundedRectangle(180.0, 780.0, 5.0);
	baseRectangle.setPosition(5.0, 415.0);
	baseRectangle.setFillColor(sf::Color::Blue);

	//Opc 1
	battleMenuOpc[0].setFont(fntTitle);
	battleMenuOpc[0].setString("Atacar");
	battleMenuOpc[0].setCharacterSize(40);
	battleMenuOpc[0].setFillColor(sf::Color::Black);
	battleMenuOpc[0].setPosition(20.0f, 410.0f);

	//Opc 2
	battleMenuOpc[1].setFont(fntTitle);
	battleMenuOpc[1].setString("Habilidad");
	battleMenuOpc[1].setCharacterSize(40);
	battleMenuOpc[1].setFillColor(sf::Color(0, 0, 0, 95));
	battleMenuOpc[1].setPosition(20.0f, 455.0f);

	//Opc 3
	battleMenuOpc[2].setFont(fntTitle);
	battleMenuOpc[2].setString("Magia");
	battleMenuOpc[2].setCharacterSize(40);
	battleMenuOpc[2].setFillColor(sf::Color::Black);
	battleMenuOpc[2].setPosition(20.0f, 500.0f);

	//Opc 4
	battleMenuOpc[3].setFont(fntTitle);
	battleMenuOpc[3].setString("Objeto");
	battleMenuOpc[3].setCharacterSize(40);
	battleMenuOpc[3].setFillColor(sf::Color::Black);
	battleMenuOpc[3].setPosition(20.0f, 545.0f);

	//Entity Name
	cEntityName.setFont(fntTitle);
	cEntityName.setString(GM.getCCharacter()->getName() + "'s Turn");
	cEntityName.setCharacterSize(40);
	cEntityName.setFillColor(sf::Color::Black);
	cEntityName.setPosition(20.0f, 20.0f);


	//Selector
	selector = sf::VertexArray(sf::TriangleStrip, 4);
	// define it as a rectangle, located at (10, 10) and with size 100x100
	selector[0].position = sf::Vector2f(10.0f, 415.0f);//	s[0]				s[2]
	selector[1].position = sf::Vector2f(10.0f, 460.0f);
	selector[2].position = sf::Vector2f(210.0f, 415.0f);
	selector[3].position = sf::Vector2f(210.0f, 460.0f);//	s[1]				s[3]

	// define its texture area to be a 25x50 rectangle starting at (0, 0)
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);
	selector[2].color = sf::Color(255, 255, 255, 0);
	selector[3].color = sf::Color(255, 255, 255, 0);

	menuOpcSelected = 0;

}

void BattleMenu::draw(sf::RenderWindow& rwindow)
{
	rwindow.draw(cEntityName);

	baseRectangle.draw(rwindow);
	rwindow.draw(selector, tSelector);
	for (int i = 0; i < BATTLE_MENU_OPTIONS; ++i) {
		rwindow.draw(battleMenuOpc[i]);
	}
}

void BattleMenu::moveUp()
{
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);
	if (menuOpcSelected - 1 >= 0)
	{
		tSelector.translate(0.0f, -45.0f);
		menuOpcSelected--;
		if (menuOpcSelected == -1)
		{
			menuOpcSelected = 2;
			tSelector.translate(0.0f, 150.0f);
		}
	}
}

void BattleMenu::moveDown()
{
	selector[0].color = sf::Color(0, 166, 255, 191);
	selector[1].color = sf::Color(0, 166, 255, 191);

	if (menuOpcSelected + 1 < BATTLE_MENU_OPTIONS)
	{
		tSelector.translate(0.0f, 45.0f);
		menuOpcSelected++;
		if (menuOpcSelected == BATTLE_MENU_OPTIONS)
		{
			menuOpcSelected = 0;
			tSelector.translate(0.0f, 150.0f);
		}
	}
}

void BattleMenu::isSelected()
{
	selector[0].color = sf::Color(0, 127, 255, 255);
	selector[1].color = sf::Color(0, 127, 255, 255);

	switch (GM.getBattleState())
	{
	case BattleState::ACTION:

		switch (menuOpcSelected)
		{
		case 0:
			std::cout << "Ataque basico" << std::endl;
			break;

		case 1:
			std::cout << "Aun no hemos implementado las habilidades" << std::endl;
			break;

		case 2:
			for (int i = 0; i < BATTLE_MENU_OPTIONS; i++)
			{
				if (i < GM.getCCharacter()->getAttacksKnown())
				{
					battleMenuOpc[i].setString(GM.getCCharacter()->getAttack(i)->getName());
				}
				else battleMenuOpc[i].setString("");
			}
			GM.ChangeBattleState(BattleState::MAGIC);
			break;

		case 3:
			GM.ChangeBattleState(BattleState::INVENTORY);
			std::cout << "Aun no esta implementado el inventario" << std::endl;
			GM.ChangeBattleState(BattleState::ACTION);
			break;

		default:
			break;
		}

		break;

	case BattleState::MAGIC:
		if (GM.getCCharacter()->getAttack(menuOpcSelected) != nullptr)
		{
			std::cout << "Se realizo el ataque " << GM.getCCharacter()->getAttack(menuOpcSelected)->getName() << std::endl;
			GM.ChangeBattleState(BattleState::ACTION);
			//GM.ChangeBattleState(BattleState::SELECT_TARGET);
		}
		else
		{
			std::cout << "Ese ataque no es valido" << std::endl;
			GM.ChangeBattleState(BattleState::ACTION);
		}		
		break;

	case BattleState::INVENTORY:

		break;

	case BattleState::SELECT_TARGET:
		//TODO: Implementar logica de Seleccion de enemigo en la pantalla
		

		//TODO: Implementar logica para luego 
		battleMenuOpc[0].setString("Attack");
		battleMenuOpc[1].setString("Ability");
		battleMenuOpc[2].setString("Magic");
		battleMenuOpc[3].setString("Item");

		break;
	}

}

BattleMenu::~BattleMenu(){}