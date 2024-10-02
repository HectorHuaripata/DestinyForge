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
    /*std::string name;
    AttackType type;
    TargetRange range;
    TargetObjective objetive;
    int power;
    int accuracy;
    int priority;*/
    // ... otros atributos para efectos secundarios, condiciones especiales, etc.
public:

    //Attack(const std::string& nombre, AttackType tipo, TargetRange alcance, TargetObjective objetivo, int potencia, int precision, int prioridad);

    // ... otros métodos (ejecutar, calcularDaño, aplicarEfectos, etc.)
    virtual void Execute(Entity* source, std::vector<Entity*> objective) = 0; //Ejecuta el ataque en general, usando las otras funciones
    //void CalculateDamage(Entity* source, Entity* objective);
    //void ApplyEffects(std::vector<Entity*> objective); //Aplica efectos como veneno, inmunidad, etc
    //bool isCritic(); //Decide si el ataque es critico
    //bool itFails(); //Cuando un ataque tiene probabilidades de fallar



    /*AttackType GetType() { return type; }
    TargetRange getTargetType() { return range; }
    TargetObjective getTargetSide() { return objetive; }
    std::string getName() { return name; }*/
};