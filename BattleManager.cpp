#include "BattleManager.hpp"
#include "GameManager.hpp"


BattleManager::BattleManager() :cTurn(0), sAttack(0), cEntityInTurn(nullptr), bState(BattleState::ACTION) {
    /*attacks.push_back(new AttackDamage("00001", "Ataque fisico", 10, 0, 0, AttackType::PHYSICAL, TargetRange::SINGLE, 80));
    attacks.push_back(new AttackDamage("00002", "Ataque magico", 15, 5, 0, AttackType::MAGIC, TargetRange::SINGLE, 90));
    attacks.push_back(new AttackDamage(
        "00003",
        "Nube toxica",
        10,
        10,
        0,
        AttackType::MAGIC,
        TargetRange::SINGLE,
        60));*/

    group.push_back(new Entity(tagEntity::HERO, "Hector", 50, 8, 6, 4, 4, 10, 20));
    group.at(0)->AddAttack(attacks[0]);
    group.at(0)->AddAttack(attacks[1]);
    //group.push_back(new Entity(tagEntity::HERO, "Miguel", 60, 10, 4, 4, 6, 8, 12, attacks[0], attacks[1], attacks[2], nullptr));

    enemies.push_back(new Entity(tagEntity::ENEMY, "Liche", 40, 3, 6, 3, 3, 8, 24));
    enemies.at(1)->AddAttack(attacks[0]);
    enemies.at(1)->AddAttack(attacks[1]);
    //enemies.push_back(new Entity(tagEntity::ENEMY, "Huargo", 40, 7, 5, 3, 3, 8, 18, attacks[0], attacks[1], attacks[2], nullptr));
}

void BattleManager::ExecuteTurn()
{
    //TODO: Replantear la entrada de datos al battle manager
    //IDEA: Crear funciones que reciban:
    // un BattleState
    // un entero(id del ataque)
    // un entero(id del objetivo, si es single target)
    // y lo almacene en una variable propia
    
    //Los parametros que necesitare: accion(BattleState), idAtaque(), objetivo(Entity* o Vector<>)
    
    // Ejecutar acción seleccionada
    switch (bState)
    {
    case BattleState::ACTION:
        sAttack = 0;
        break;
    case BattleState::MAGIC:
        sAttack = GM.getCMenu()->MainMenuPressed();
        //bState = BattleState::ACTION;
        break;
    case BattleState::INVENTORY:
        //Abrir Menu inventario batalla
        break;
    case BattleState::SELECT_TARGET:
        //Abrir Menu para seleccionar objetivo
        break;
    default:
        break;
    }

    //TODO:Cambiar el if por un switch
    if (cEntityInTurn->getTag() == tagEntity::HERO) {
        cEntityInTurn->doAttack(sAttack, enemies[0]);
    }
    else if (cEntityInTurn->getTag() == tagEntity::ENEMY) {
        cEntityInTurn->doAttack(sAttack, group[0]);
    }

    bState = BattleState::ACTION;

    //TODO: Encapsular lo siguiente en una funcion
    if (WinCondition()) //win conditions
    {
        std::cout << "Ganas la batalla." << std::endl;
        // Finalizar el combate, mostrar recompensas, volver al menú principal, etc.
        EndBattle();
        
    }
    else if (LoseCondition()) { //defeat conditions
        std::cout << "Pierdes la batalla." << std::endl;
        // Finalizar el juego, mostrar pantalla de game over, etc.
        EndBattle();
    }
    else
    {
        NextTurn();
    }    
}

void BattleManager::ChangeBattleState(BattleState battleState)
{
    bState = battleState;
}

void BattleManager::StartBattle()
{
    //TODO: Inicializar el orden de los turnos
    DefineTurns();
    sAttack = -1;
    //TODO: Implementar algoritmo para ordenar los elementos segun su velocidad
    cEntityInTurn = ordenTurnos[cTurn % ordenTurnos.size()];
    cTurn = 1;
}

void BattleManager::EndBattle()
{

    //TODO: Agregar experiencia ganada por cada personaje, ademas de objetos del botin agregados al inventario, y estadisticas si subio de nivel
    cEntityInTurn = nullptr;
    cTurn = 0;
    sAttack = -1;
    //TODO: Limpiar el orden de los turnos, pero solo de los enemigos para que luego no demora en cargar
    //A menos que el usuario haya modificado su grupo
    ordenTurnos.clear();
    GM.ChangeGameState(GameState::START);
}

void BattleManager::DefineTurns()
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
            else if (ordenTurnos[i]->getSpeed() < var->getSpeed()) {
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
            else if (ordenTurnos[i]->getSpeed() < var->getSpeed()) {
                ordenTurnos.insert(ordenTurnos.begin() + i, var);
                break;
            }
        }
    }
}

void BattleManager::NextTurn()
{
    cEntityInTurn = ordenTurnos[cTurn % ordenTurnos.size()];
    GM.getCMenu()->update();
    cTurn++;
}

void BattleManager::Action()
{
    //TODO: Implementar un validador para que la id del ataque y el indice del objetivo sean validos

    switch (bState)
    {
    case BattleState::ACTION:
        switch (GM.getCMenu()->MainMenuPressed())
        {
        case 0:
            //Uso del ataque por defecto del cCharacter
            ExecuteTurn();
            break;
        case 1:            
            std::cout << "Aun no hay habilidades" << std::endl;
            break;
        case 2:
            ChangeBattleState(BattleState::MAGIC);
            GM.getCMenu()->update();
            break;
        case 3:
            ChangeBattleState(BattleState::INVENTORY);
            std::cout << "No tienes objetos." << std::endl;
            ChangeBattleState(BattleState::ACTION);
            break;
        default:
            break;
        }
        break;
    case BattleState::MAGIC:
        if (GM.getCMenu()->MainMenuPressed()<GM.getCCharacter()->getAttacksKnown())
            ExecuteTurn(); //Uso de la magia en la pos MainMenuPressed del cCharacter
        else
        {
            std::cout << "Opcion no valida." << std::endl;
            ChangeBattleState(BattleState::ACTION);
            GM.getCMenu()->update();
        }
        break;
    case BattleState::INVENTORY:
        //El input aqui vendra de otro menu llamado Battle Inventory Menu
        break;
    case BattleState::SELECT_TARGET:

        break;
    default:

        break;
    }
}

bool BattleManager::WinCondition()
{
    //TODO: OPTIMIZAR. MUUUUUUUY LENTO
    for (Entity* var : enemies)
    {
        if (var->getCurrentHealth() > 0) return false;
    }
    return true;
}

bool BattleManager::LoseCondition()
{
    //TODO: OPTIMIZAR. MUUUUUUUY LENTO
    for (Entity* var : group)
    {
        if (var->getCurrentHealth() > 0) return false;
    }
    return true;
}
