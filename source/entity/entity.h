#pragma once
#include "point.h"

/*
Clase Entity:
Se encarga de manejar las funciones y datos principales de las entidades, como su velocidad, posición, tamaño, inicializarse, desplazarce e interactuar con el encuentro con otras entidades. Acá se utiliza como una interfáz.
*/
class Entity
{
private:
    int _sizeX = 0; // Cuantas celdas de ancho ocupan (se asume que en y siempre ocupan 1).
    float _velocity = 0; // Cuantas celdas avanzan por segundo.
    Point position{ 0,0 }; // Posición en la grilla.
    bool isCar = true; // Indica si es vehículo o jugador.

public:
    // Entity: const int  const float  const Point -> Entity
    //Inicializa la entidad, recibiendo su tamaño, velocidad y posición inicial.
    Entity(const int size, const float velocity, const Point& Aposition);

    // Entity: void -> Entity
    // Crea la entidad Player, que será el personaje controlado por el jugador, es de tamaño 1, tendrá velocidad 1 y comenzará en la zona inferior de la grilla.
    Entity();

    // Entity: const int const float -> Entity
    // Crea la entidad Car, que tendrá un tamaño y velocidad determinado.
    Entity(const int size, const float velocity);

    // getSize: void -> int
    // Obtiene el tamaño de la entidad
    int getSize() const;

    // getPos: void -> Point
    // Obtener posición en la grilla.
    Point getPos() const;

    // setPos: const Point -> void
    // Designa una nueva posición.
    void setPos(const Point& Aposition);

    // colision: Entity& -> void
    // Interactua con la entidad con la que colisiona al avanzar una casilla.
    void colision(Entity& entity);

    // Permite obtener la impresión de la entidad, mostrando su ubicación y tamaño.
    friend std::ostream& operator<<(std::ostream& out, const Entity& entity);
};
