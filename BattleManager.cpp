#include "BattleManager.hpp"
#include "GameManager.hpp"

BattleManager::BattleManager() :cTurn(0), sAttack(0), cEntityInTurn(nullptr), bState(BattleState::ACTION) {
    attacks.push_back(new AttackDamage("Ataque fisico", 10, 0, AttackType::PHYSICAL, TargetRange::SINGLE, TargetObjective::RIVAL));
    attacks.push_back(new AttackDamage("Ataque magico", 15, 5, AttackType::MAGIC, TargetRange::SINGLE, TargetObjective::RIVAL));

    group.push_back(new Entity(tagEntity::HERO, "Hector", 50, 8, 6, 4, 4, 10, 20, attacks[0], attacks[1], nullptr, nullptr));
    //group.push_back(new Entity(tagEntity::HERO, "Miguel", 60, 10, 4, 4, 6, 8, 12, attacks[0], attacks[1], attacks[2], nullptr));

    enemies.push_back(new Entity(tagEntity::ENEMY, "Liche", 60, 7, 5, 6, 6, 8, 18, attacks[0], attacks[1], nullptr, nullptr));
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
    //TODO:Cambiar el if por un switch
    if (bState == BattleState::ACTION)
    {
        sAttack = 0;
    }
    else {
        sAttack = GM.getCMenu()->MainMenuPressed();
        bState = BattleState::ACTION;
    }

    if (cEntityInTurn->getTag() == tagEntity::HERO) {
        cEntityInTurn->doAttack(sAttack, enemies[0]);
    }
    else if (cEntityInTurn->getTag() == tagEntity::ENEMY) {
        cEntityInTurn->doAttack(sAttack, group[0]);
    }

    //TODO: Encapsular lo siguiente en una funcion
    if (false) //win conditions
    {
        // Finalizar el combate, volver al menú principal, etc.
        EndBattle();
        GM.ChangeGameState(GameState::DUNGEON);
    }
    else if (false) { //defeat conditions
        EndBattle();
        // Finalizar el juego, mostrar pantalla de game over, etc.        
    }

    cEntityInTurn = ordenTurnos[cTurn % ordenTurnos.size()];
    GM.getCMenu()->update();
    cTurn++;
}

void BattleManager::ChangeBattleState(BattleState battleState)
{
    bState = battleState;
}

void BattleManager::StartBattle()
{
    bState = BattleState::ACTION;
    //TODO: Inicializar el orden de los turnos
    DefineTurns();
    //TODO: Implementar algoritmo para ordenar los elementos segun su velocidad
    cEntityInTurn = ordenTurnos[cTurn % ordenTurnos.size()];
    cTurn = 1;
}

void BattleManager::EndBattle()
{
    //TODO: Agregar experiencia ganada por cada personaje, ademas de objetos del botin agregados al inventario, y estadisticas si subio de nivel
    cEntityInTurn = nullptr;
    cTurn = 0;
    sAttack = 0;
    //TODO: Limpiar el orden de los turnos
    GM.ChangeGameState(GameState::DUNGEON);
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

void BattleManager::Action()
{
    //TODO: Implementar un validador para que la id del ataque y el indice del objetivo sean validos
    
   /* if (cEntityInTurn->getAttack(attackID)->getTargetType() == TargetRange::SINGLE )
    {
        cEntityInTurn->doAttack(attackID, cEntityInTurn->getTag() == tagEntity::HERO ? enemies[objective] : group[objective]);
    }

    if (cEntityInTurn->getTag() == tagEntity::HERO) {
        if (false)
        {

        }
        cEntityInTurn->doAttack(sAttack, enemies[(cTurn / 4) % 2]);
    }
    else if (cEntityInTurn->getTag() == tagEntity::ENEMY) {
        cEntityInTurn->doAttack(sAttack, group[(cTurn / 4) % 2]);
    }*/
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
        //Uso de la magia en la pos 0 del cCharacter
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