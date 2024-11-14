#pragma once

#include <iostream>
#include <string>

class Entity;
enum class AttackType { PHYSICAL, MAGIC, STATE };
enum class TargetRange { USER, SINGLE, TEAM, OTHERS, ALL };

class Attack {
public:

    // ... otros métodos (ejecutar, calcularDaño, aplicarEfectos, etc.)
    virtual void Execute(Entity* source, Entity* objective) = 0; //Ejecuta el ataque en general, usando las otras funciones
    
    /*TargetObjective getTargetSide() { return objetive; }*/
    
    virtual inline const std::string& getName() const = 0;
    virtual inline const std::string& getId() const = 0;
    virtual inline AttackType GetType() = 0;
    virtual inline TargetRange getTargetType() = 0;
    virtual inline const unsigned int getPriority() const = 0;
    virtual inline const unsigned int getCost() const = 0;
    //TODO: Pensar en manera de implementar flags
};