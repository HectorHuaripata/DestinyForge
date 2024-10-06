#include "BattleMenu.hpp"
#include "GameManager.hpp"

BattleMenu::BattleMenu()
{
	if (!fntTitle.loadFromFile("Fonts/Gabriola.ttf"))
		std::cerr << "Error al cargar la fuente" << std::endl;

	//Base Rectangle
	baseRectangle = RoundedRectangle(180.0, 780.0, 5.0);
	baseRectangle.setPosition(5.0, 415.0);
	baseRectangle.setFillColor(sf::Color(0,0,255,64));

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

	//Group members names
	nameMemberGroup.setFont(fntTitle);
	nameMemberGroup.setString(GM.getGroupMember(0)->getName());
	nameMemberGroup.setCharacterSize(25);
	nameMemberGroup.setFillColor(sf::Color::Black);
	nameMemberGroup.setPosition(20.0f, 220.0f);

	//health & mana bars of group
	healthBarGroup.setSize(sf::Vector2f(BAR_MAX_SIZE, 10.0f));
	healthBarGroup.setPosition(20.0f, 250.0f);
	healthBarGroup.setOrigin(0.0f, 5.0f);
	healthBarGroup.setFillColor(sf::Color::Green);

	manaBarGroup.setSize(sf::Vector2f(BAR_MAX_SIZE, 10.0f));
	manaBarGroup.setPosition(20.0f, 260.0f);
	manaBarGroup.setOrigin(0.0f, 5.0f);
	manaBarGroup.setFillColor(sf::Color::Blue);

	//Enemies members names
	nameMemberEnemies.setFont(fntTitle);
	nameMemberEnemies.setString(GM.getEnemiesMember(0)->getName());
	nameMemberEnemies.setCharacterSize(25);
	nameMemberEnemies.setFillColor(sf::Color::Black);
	nameMemberEnemies.setPosition(550.0f, 220.0f);

	//health & mana bars of enemies
	healthBarEnemies.setSize(sf::Vector2f(BAR_MAX_SIZE, 10.0f));
	healthBarEnemies.setPosition(550.0f, 250.0f); 
	healthBarEnemies.setOrigin(0.0f, 5.0f);
	healthBarEnemies.setFillColor(sf::Color::Green);

	manaBarEnemies.setSize(sf::Vector2f(BAR_MAX_SIZE, 10.0f));
	manaBarEnemies.setPosition(550.0f, 260.0f); 
	manaBarEnemies.setOrigin(0.0f, 5.0f);
	manaBarEnemies.setFillColor(sf::Color::Blue);


	//Entity Name
	cEntityName.setFont(fntTitle);
	cEntityName.setString(GM.getCCharacter()->getName() + "'s Turn");
	cEntityName.setCharacterSize(40);
	cEntityName.setFillColor(sf::Color::Black);
	cEntityName.setPosition(20.0f, 370.0f);


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

	rwindow.draw(nameMemberGroup);
	rwindow.draw(healthBarGroup);
	rwindow.draw(manaBarGroup);

	rwindow.draw(nameMemberEnemies);
	rwindow.draw(healthBarEnemies);
	rwindow.draw(manaBarEnemies);


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

void BattleMenu::update()
{
	cEntityName.setString(GM.getCCharacter()->getName() + "'s Turn");
	float percentPlayerHealth = BAR_MAX_SIZE * GM.getGroupMember(0)->getCurrentHealth() / GM.getGroupMember(0)->getMaxHealth();
	float percentPlayerMana = BAR_MAX_SIZE * GM.getGroupMember(0)->getCurrentMana() / GM.getGroupMember(0)->getMaxMana();
	float percentEnemyHealth = BAR_MAX_SIZE * GM.getEnemiesMember(0)->getCurrentHealth() / GM.getEnemiesMember(0)->getMaxHealth();
	float percentEnemyMana = BAR_MAX_SIZE * GM.getEnemiesMember(0)->getCurrentMana() / GM.getEnemiesMember(0)->getMaxMana();
	healthBarGroup.setSize(sf::Vector2f(percentPlayerHealth, 10.0f));
	manaBarGroup.setSize(sf::Vector2f(percentPlayerMana, 10.0f));
	healthBarEnemies.setSize(sf::Vector2f(percentEnemyHealth, 10.0f));
	manaBarEnemies.setSize(sf::Vector2f(percentEnemyMana, 10.0f));

	switch (GM.getBattleState())
	{
	case BattleState::ACTION:
		battleMenuOpc[0].setString("Atacar");
		battleMenuOpc[1].setString("Habilidad"); 
		battleMenuOpc[2].setString("Magia");
		battleMenuOpc[3].setString("Objeto");
		break;

	case BattleState::MAGIC:

		for (size_t i = 0; i < BATTLE_MENU_OPTIONS; i++)
		{
			if (i < GM.getCCharacter()->getAttacksKnown())
				battleMenuOpc[i].setString(GM.getCCharacter()->getAttack(i)->getName());
			else
				battleMenuOpc[i].setString("");
		}
		break;

	case BattleState::INVENTORY:
		
		break;

	case BattleState::SELECT_TARGET:

		break;

	default:
		break;
	}
}

BattleMenu::~BattleMenu(){}