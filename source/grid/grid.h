#pragma once
#include "vector"
#include "../entity/entity.h"

/*
Clase Grid:
Una grilla que representa el mapa, tiene un tamaño de n x n casillas, donde cada una de estas casillas identificará si está vacío (0),
si tiene al jugador (1) o si es un vehículo transitando (2). Además permitirá el movimiento de estas entidades.
*/
class Grid
{
private:
    int size; // Tamaño de la grilla.
    std::vector<std::vector<Entity*>> grid; // La grilla.
public:
    // Grid: const int -> Grid
    // Constructor que recibe un entero n y define una grilla de tamaño n x n.
    Grid(const int n);

    // getGrid: void -> const vector<vector<Entity*>>&
    // Obtiene la grilla en cuestión.
    const std::vector<std::vector<Entity*>>& getGrid() const;

    // canMove: const Point&  const Point& -> bool
    // Verifica que la entidad de la posición antigua se pueda desplazar a la posición indicada, además llama a la interacción entre entidades si la hay y la desplaza.
    bool canMove(const Point& oldPosition, const Point& position);

    // move: Entity& const Point& -> void
    // Desplaza a la siguiente casilla la entidad en la dirección entregada como punto con la velocidad designada.
    void move(Entity& entity, const Point& direction);

    // getEntity: const Point& -> Entity*
    // Obtiene la entidad que se encuentre en la posición indicada.
    Entity* getEntity(const Point& position);

    // setEntity: const Point& Entity& -> void
    // Setea la posición de la entidad, utilizada para inicializar.
    void setEntity(const Point& position, Entity& Entity);

};

// Permite la impresión de la grilla, desplegando que entidades se encuentran.
std::ostream &operator<<(std::ostream& out, const Grid& c);