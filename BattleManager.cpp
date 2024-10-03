#include "BattleManager.hpp"
#include "GameManager.hpp"

void BattleManager::ExecuteTurn()
{
    //TODO: Replantear la entrada de datos al battle manager
    //IDEA: Crear funciones que reciban:
    // un BattleState
    // un entero(id del ataque)
    // un entero(id del objetivo, si es single target)
    // y lo almacene en una variable propia
    
    //Los parametros que necesitare: accion(BattleState), idAtaque(), objetivo(Entity* o Vector<>)
    switch (bState)
    {
    case BattleState::ACTION:

        break;
    case BattleState::MAGIC:
                
        break;
    case BattleState::INVENTORY:
        //El input aqui vendra de otro menu llamado Battle Inventory Menu
        break;
    case BattleState::SELECT_TARGET:

        break;
    default:

        break;
    }

    // Ejecutar acción seleccionada
    sAttack = GM.getCMenu()->MainMenuPressed();

    //if(cCharacter->getTag() == tagEntity::HERO && sAttack > -1 && sAttack < attacks.size())
    if (cEntityInTurn->getTag() == tagEntity::HERO) {
        cEntityInTurn->doAttack(sAttack, enemies);
    }
    else if (cEntityInTurn->getTag() == tagEntity::ENEMY) {
        cEntityInTurn->doAttack(sAttack, group);
    }

    bState = BattleState::ACTION;
    cEntityInTurn = ordenTurnos[cTurn % ordenTurnos.size()];
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
    cTurn = 0;
}

void BattleManager::EndBattle()
{
    //TODO: Agregar experiencia ganada por cada personaje, ademas de objetos del botin agregados al inventario, y estadisticas si subio de nivel
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

void BattleManager::Action(int attackID, int objective, bool toRival)
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
}