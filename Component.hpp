#pragma once

#include "Entity.hpp"

class Component {
public:
    virtual void Execute(Entity* source, Entity* objective) = 0;// Este método se llama cuando el componente se activa, como al usar una habilidad
    virtual void Update(Entity* source) = 0; // Este método se llama periódicamente para actualizar el estado del componente, por ejemplo, para verificar si un efecto de estado ha terminado.
    virtual void onAcquire(Entity* source) = 0; // Se llama cuando el componente es adquirido por una entidad.
    virtual void onRemove(Entity* source) = 0; // Se llama cuando el componente es eliminado de una entidad.
};

//  EJEMPLO DE IMPLEMENTACION DE COMPONENTE
// class EfectoQuemado : public Componente {
//public:
//    void ejecutar(Entidad* objetivo) override {
//        // Infligir daño inicial
//        objetivo->recibirDaño(10);
//        // Aplicar el estado de quemado
//        objetivo->agregarEstado(new EstadoQuemado(3, 5)); // Duración: 3 turnos, daño por turno: 5
//    }
//
//    void actualizar(Entidad* entidad) override {
//        // Si la entidad tiene el estado de quemado, infligir daño cada turno
//        if (entidad->tieneEstado("Quemado")) {
//            entidad->recibirDaño(5);
//        }
//    }
//
//    void onAdquisicion(Entidad* entidad) override {
//        // Cuando se aplica el efecto, se puede mostrar un mensaje al jugador
//        std::cout << "El objetivo está en llamas!" << std::endl;
//    }
//
//    void onEliminacion(Entidad* entidad) override {
//        // Cuando se elimina el efecto, se puede mostrar un mensaje al jugador
//        std::cout << "Las llamas se han extinguido." << std::endl;
//    }
//};

//class Escudo : public Componente {
//public:
//    int valorEscudo;
//
//    void onAdquisicion(Entidad* entidad) override {
//        entidad->setEscudo(valorEscudo);
//    }
//
//    void actualizar(Entidad* entidad) override {
//        // Reducir el escudo si ha recibido daño
//        if (entidad->recibirDaño(valorEscudo)) {
//            entidad->setEscudo(0);
//            onEliminacion(entidad);
//        }
//    }
//
//    void onEliminacion(Entidad* entidad) override {
//        entidad->setEscudo(0);
//        std::cout << "El escudo se ha roto." << std::endl;
//    }
//};
//
//class RegeneracionMana : public Componente {
//public:
//    float regeneracionPorTurno;
//
//    void actualizar(Entidad* entidad) override {
//        entidad->aumentarMana(regeneracionPorTurno);
//    }
//};


class ComponentActivation : public Component{
    virtual bool checkCondition(Entity* source) = 0;
};

class ComponentEffect : public Component {
};

class ComponentInteraction : public Component {
};

class ComponentState : public Component {
};