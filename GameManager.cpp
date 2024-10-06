#include "GameManager.hpp"

void GameManager::Initialize()
{
    bManager = new BattleManager();
    cMenu = new MainMenu;
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
                Action();
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
}

void GameManager::Quit()
{
}

void GameManager::StartMap()
{

}

void GameManager::ChangeGameState(GameState gameState) {
    delete(cMenu);
    gState = gameState;
    switch (gState)
    {
    case GameState::START:
        cMenu = new MainMenu;
        break;

    case GameState::BATTLE:
        bManager->StartBattle();
        cMenu = new BattleMenu;
        break;

    case GameState::DUNGEON:
        

    case GameState::WORLD_MAP:
        cMenu = new InGameMenu;
        break;

    case GameState::DIALOGUE:
        break;

    case GameState::SHOP:
        break;

    default:
        break;
    }    
}

void GameManager::ChangeBattleState(BattleState battleState)
{
    bManager->ChangeBattleState(battleState);
}

void GameManager::Action() {
    switch (gState)
    {
    case GameState::START:
        switch (cMenu->MainMenuPressed())
        {
        case 0:
            ChangeGameState(GameState::BATTLE);
            break;
        case 1:
            std::cout << "No tienes partida guardada." << std::endl;
            break;
        case 2:
            std::cout << "No hay ajustes aun" << std::endl;
            break;
        case 3:
            std::cout << "Aun estoy desarrollando el contenido extra" << std::endl;
            break;

        default:
            std::cout << "Informanos como llegaste aqui... por favor" << std::endl;
            break;
        }
        break;

    case GameState::BATTLE:
        bManager->Action();
        break;

    case GameState::WORLD_MAP:
        break;

    case GameState::DUNGEON:
        break;

    case GameState::DIALOGUE:
        break;

    case GameState::SHOP:
        break;
    }
}