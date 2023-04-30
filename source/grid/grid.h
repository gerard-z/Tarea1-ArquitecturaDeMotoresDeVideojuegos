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
    float boxsize; // Tamaño de los cuadrados a dibujar
public:
    // Grid: const int -> Grid
    // Constructor que recibe un entero n y define una grilla de tamaño n x n.
    Grid(const int n);

    // gridToCanvas: const int -> const float
    // Transforma las coordenadas de la grilla en la coordenada para la pantalla.
    const float gridToCanvas(const int pos);

    // gridToCanvas: const float -> const float
    // Transforma las coordenadas de la grilla en la coordenada para la pantalla.
    const float gridToCanvas(const float pos);

    // getGrid: void -> const vector<vector<Entity*>>&
    // Obtiene la grilla en cuestión.
    const std::vector<std::vector<Entity*>>& getGrid() const;

    // canMove: const Point& const Point& const Point& BoxRenderer::Canvas-> bool
    // Verifica que la entidad de la posición antigua se pueda desplazar a la posición indicada, además llama a la interacción entre entidades si la hay y la desplaza.
    bool canMove(const Point& oldPosition, const Point& position, const Point& direction2, BoxRenderer::Canvas& canvas);

    // move: Entity& const Point& BoxRenderer::Canvas& -> void
    // Desplaza a la siguiente casilla la entidad en la dirección entregada como punto con la velocidad designada y modifica la visualización.
    void move(Entity& entity, const Point& direction, BoxRenderer::Canvas& canvas);

    // moveTo: Entity& const Point BoxRenderer::Canvas& -> void
    // Desplaza la entidad a la posición indicada.
    void moveTo(Entity& entity, const Point& destiny, BoxRenderer::Canvas& canvas);

    // getEntity: const Point& -> Entity*
    // Obtiene la entidad que se encuentre en la posición indicada.
    Entity* getEntity(const Point& position);

    // setEntity: const Point& Entity& -> void
    // Setea la posición de la entidad, utilizada para inicializar. Además, otorga la representación visual de la entidad.
    void setEntity(const Point& position, Entity& Entity);

};

// Permite la impresión de la grilla, desplegando que entidades se encuentran.
std::ostream &operator<<(std::ostream& out, const Grid& c);