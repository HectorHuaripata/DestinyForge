#pragma once
#ifndef ATTACK_HPP
#define ATTACK_HPP
#endif

#include <iostream>
#include <vector>
#include <string>

class Entity;

enum class AttackType { PHYSICAL, MAGIC, STATE };
enum class TargetRange { SINGLE, TEAM, ALL };
enum class TargetObjective {SELF, ALLY, RIVAL};

class Attack {
private:
    
public:

    //Attack(const std::string& nombre, AttackType tipo, TargetRange alcance, TargetObjective objetivo, int potencia, int precision, int prioridad);

    // ... otros métodos (ejecutar, calcularDaño, aplicarEfectos, etc.)
    virtual void Execute(Entity* source, Entity* objective) = 0; //Ejecuta el ataque en general, usando las otras funciones
    //void CalculateDamage(Entity* source, Entity* objective);
    //void ApplyEffects(std::vector<Entity*> objective); //Aplica efectos como veneno, inmunidad, etc
    //bool isCritic(); //Decide si el ataque es critico
    //bool itFails(); //Cuando un ataque tiene probabilidades de fallar



    /*AttackType GetType() { return type; }
    TargetRange getTargetType() { return range; }
    TargetObjective getTargetSide() { return objetive; }*/
    //virtual inline const int getCost() = 0; 
    virtual inline const std::string& getName() const = 0;
};