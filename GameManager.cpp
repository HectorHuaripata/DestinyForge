#include "GameManager.hpp"
#include "MainMenu.h"

void GameManager::Initialize(sf::RenderWindow& rwindow)
{
    cMenu = new MainMenu();
    rwindow.setFramerateLimit(60);

    attacks.push_back(new AttackDamage("Ataque fisico", 8, 5, AttackType::PHYSICAL, TargetType::SINGLE));
    attacks.push_back(new AttackDamage("Ataque magico", 10, 7, AttackType::MAGIC, TargetType::SINGLE));
    attacks.push_back(new AttackDamage("Tormenta", 12, 10, AttackType::MAGIC, TargetType::MULTI));

    group.push_back(new Entity(tagEntity::HERO, "Hector", 50, 8, 6, 4, 4, 10, 20, attacks[0], attacks[1], nullptr, nullptr));
    group.push_back(new Entity(tagEntity::HERO, "Miguel", 60, 10, 4, 4, 6, 8, 12, attacks[0], attacks[1], attacks[2], nullptr));

    enemies.push_back(new Entity(tagEntity::ENEMY, "Liche", 60, 7, 5, 6, 6, 8, 18, attacks[0], attacks[1], nullptr, nullptr));
    enemies.push_back(new Entity(tagEntity::ENEMY, "Huargo", 40, 7, 5, 3, 3, 8, 18, attacks[0], attacks[1], attacks[2], nullptr));
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

void GameManager::StartBattle()
{
    bState = BattleState::ACTION;
    //TODO: Inicializar el orden de los turnos
    DefineTurns();
    //TODO: Implementar algoritmo para ordenar los elementos segun su velocidad
    cEntityInTurn = ordenTurnos[cTurn % ordenTurnos.size()];
    cTurn = 0;
}

void GameManager::StartMap()
{

}

void GameManager::ExecuteTurn()
{
    // Ejecutar acción seleccionada
    sAttack = cMenu->MainMenuPressed();

    //if(cCharacter->getTag() == tagEntity::HERO && sAttack > -1 && sAttack < attacks.size())
    if (cEntityInTurn->getTag() == tagEntity::HERO) {
        if (false)
        {

        }
        cEntityInTurn->doAttack(sAttack, enemies[(cTurn / 4) % 2]);
    }
    else if (cEntityInTurn->getTag() == tagEntity::ENEMY) {
        cEntityInTurn->doAttack(sAttack, group[(cTurn / 4) % 2]);
    }

    bState = BattleState::ACTION;
    cEntityInTurn = ordenTurnos[cTurn % ordenTurnos.size()];
    cTurn++;
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
        StartBattle();
        break;

    case GameState::DUNGEON:
        

    case GameState::WORLD_MAP:
        cMenu = new InGameMenu;
        break;

    default:
        break;
    }
    
}

void GameManager::ChangeBattleState(BattleState battleState)
{
    bState = battleState;
}

void GameManager::DefineTurns()
{
    //TODO: El orden de los turnos de los heroes ya deberia estar definido al iniciar el programa y solo se
    // actualizaria cuando se agrega o elimina un heroe. Asi, cada que inicia una batalla, solo se agregaria
    // el orden de los enemigos; Y eliminarlos del arreglo despues de terminar la batalla.
    for (Entity* var : group)
    {
        for (int i = 0; i < MAX_TEAM_MEMBERS; i++)
        {
            if (ordenTurnos.size() == i) {
                ordenTurnos.push_back(var);
                break;
            }
            else if (ordenTurnos[i]->getSpeed() > var->getSpeed()) {
                ordenTurnos.insert(ordenTurnos.begin() + i, var);
                break;
            }
        }
    }

    for (Entity* var : enemies)
    {
        for (int i = 0; i < MAX_TEAM_MEMBERS * 2; i++)
        {
            if (ordenTurnos.size() == i) {
                ordenTurnos.push_back(var);
                break;
            }
            else if (ordenTurnos[i]->getSpeed() > var->getSpeed()) {
                ordenTurnos.insert(ordenTurnos.begin() + i, var);
                break;
            }
        }
    }
}
