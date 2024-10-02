#include "GameManager.hpp"
#include "MainMenu.h"

void GameManager::Initialize(sf::RenderWindow& rwindow)
{
    cMenu = new MainMenu();
    rwindow.setFramerateLimit(60);
}

void GameManager::Update(sf::RenderWindow& rwindow, sf::Event& ev)
{
    
    while (rwindow.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            rwindow.close();
        if (ev.type == sf::Event::KeyReleased)
        {
            if (ev.key.code == sf::Keyboard::Up || ev.key.code == sf::Keyboard::W)
            {
                cMenu->moveUp();
                break;
            }
            if (ev.key.code == sf::Keyboard::Down || ev.key.code == sf::Keyboard::S)
            {
                cMenu->moveDown();
                break;
            }
            if (ev.key.code == sf::Keyboard::Return)
            {
                cMenu->isSelected();
                break;
            }
        }
    }

    // Clear the whole window before rendering a new frame
    rwindow.clear(sf::Color::White);

    // Drawing graphics

    cMenu->draw(rwindow);

    // Display the current frame
    rwindow.display();
    /*
    switch (gState)
    {

    case GameState::BATTLE:

        switch (cMenu->MainMenuPressed())
        {
        case 0:
            if (bState == BattleState::MAGIC)
            {
                //Uso de la magia en la pos 0 del cCharacter
                
            }
            else
            {
                //Uso del ataque por defecto del cCharacter
                ExecuteTurn();
            }

            break;
        case 1:
            if (bState == BattleState::MAGIC)
            {
                ExecuteTurn();
                bState = BattleState::ACTION;
            }
            else
            {
                std::cout << "Aun no hay habilidades" << std::endl;
            }
            break;
        case 2:
            if (bState == BattleState::MAGIC)
            {
                std::cout << "Ese ataque aun no esta disponible" << std::endl;
                bState = BattleState::ACTION;
            }
            else
            {
                bState = BattleState::MAGIC;
            }
            break;
        case 3:
            if (bState == BattleState::MAGIC)
            {
                std::cout << "Ese ataque aun no esta disponible" << std::endl;
                bState = BattleState::ACTION;
            }
            else
            {
                std::cout << "No tienes objetos." << std::endl;
            }

            break;
        default:
            break;
        }


        //TODO: Encapsular lo siguiente en una funcion
        if (false) //win conditions
        {
            // Finalizar el combate, volver al menú principal, etc.
            cEntityInTurn = nullptr;
            //TODO: Limpiar el orden de los turnos
            cTurn = 0;
            gState = GameState::DUNGEON;
            ChangeGameState(GameState::DUNGEON);
        }
        else if (false) { //defeat conditions

            //TODO: Limpiar el orden de los turnos
            // Finalizar el juego, mostrar pantalla de game over, etc.
            cEntityInTurn = nullptr;
            cTurn = 0;
        }

        break;

    default:
        break;
    }*/
}

void GameManager::Quit()
{
}

void GameManager::StartMap()
{

}

void GameManager::ExecuteTurn()
{

}

void GameManager::ChangeGameState(GameState gameState) {
    delete(cMenu);
    gState = gameState;
    switch (gState)
    {
    case GameState::START:
        cMenu = new MainMenu();
        break;

    case GameState::BATTLE:
        cMenu = new BattleMenu;
        bManager->StartBattle();
        break;

    case GameState::DUNGEON:
        

    case GameState::WORLD_MAP:
        cMenu = new InGameMenu;
        break;

    default:
        break;
    }    
}