#pragma once
#include "point.h"
#include "../../box_renderer/source/box_renderer.h"


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
    BoxRenderer::Color color; // Color de la representación visual.
    BoxRenderer::Box box{ {0,0}, BoxRenderer::Color::White(), {1,1} }; // Representación visual de la entidad.
    BoxRenderer::BoxId idBox; // Identificador de su representación visual en el canvas.

public:
    // Entity: const int  const float  const Point const BoxRenderer::Color const BoxRenderer::Box -> Entity
    //Inicializa la entidad, recibiendo su tamaño, velocidad, color, box y posición inicial.
    Entity(const int size, const float velocity, const Point& Aposition, const BoxRenderer::Color Acolor, const BoxRenderer::Box Abox);

    // Entity: void -> Entity
    // Crea la entidad Player, que será el personaje controlado por el jugador, es de tamaño 1, tendrá velocidad 1 y comenzará en la zona inferior de la grilla.
    Entity();

    // Entity: const int const float const BoxRenderer::Color -> Entity
    // Crea la entidad Car, que tendrá un tamaño y velocidad determinado, junto al color, que por default es azul.
    Entity(const int size, const float velocity, const BoxRenderer::Color Acolor);

    // getType: void -> const bool
    // obtiene el tipo de entidad, jugador o vehículo.
    const bool getType();

    // getSize: void -> int
    // Obtiene el tamaño de la entidad
    int getSize() const;

    // getPos: void -> Point&
    // Obtener posición en la grilla.
    Point getPos() const;

    // setPos: const Point -> void
    // Designa una nueva posición.
    void setPos(const Point& Aposition);

    // getColor: void -> BoxRenderer::Color&
    // retorna el color de la representación visual
    BoxRenderer::Color& getColor();

    // setColor: const BoxRenderer::Color -> void
    // Asigna un nuevo color a la entidad.
    void setColor(const BoxRenderer::Color acolor);

    // getBox: void -> BoxRenderer::Box&
    // retorna la caja de representación visual.
    BoxRenderer::Box& getBox();

    // setBox: const BoxRenderer::Box -> void
    // Designa la caja de representación visual.
    void setBox(const BoxRenderer::Box& abox);

    // setBox: const BoxRenderer::BoxId -> void
    // Designa la nueva representación visual junto a su identificador en el canvas.
    void setBox(const BoxRenderer::BoxId aID, BoxRenderer::Canvas& canvas);

    // getIDBox: void -> BoxRenderer::BoxId&
    // retorna el identificador de la caja de representación visual.
    BoxRenderer::BoxId& getIDBox();

    // setIDBOX: const BoxRenderer::BoxId -> void
    // Designa el identificador de la caja de representación visual.
    void setIDBox(const BoxRenderer::BoxId aID);

    // colision: Entity& -> void
    // Interactua con la entidad con la que colisiona al avanzar una casilla.
    void colision(Entity& entity);

    // Permite obtener la impresión de la entidad, mostrando su ubicación y tamaño.
    friend std::ostream& operator<<(std::ostream& out, const Entity& entity);
};
