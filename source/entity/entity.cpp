#include "entity.h"


Entity::Entity(const int size, const float velocity, const Point& Aposition)
{
    _sizeX = size;
    _velocity = velocity;
    position = Aposition;
}

Entity::Entity()
{
    _sizeX = 1;
    _velocity = 1;
    position = Point{ 0,0 };
    isCar = false;
}

Entity::Entity(const int size, const float velocity)
{
    _sizeX = size;
    _velocity = velocity;
    position = Point{ 0,0 };
}

void Entity::colision(Entity &entity)
{
    std::cout << "Colisión de" << *this << " con " << entity << std::endl;
}

int Entity::getSize() const {
    return _sizeX;
}

Point Entity::getPos() const{
    return position;
}

void Entity::setPos(const Point& Aposition){
    position = Aposition;
}

std::ostream& operator<<(std::ostream& out, const Entity& entity) {
    if (entity.isCar){
        out << "V" << entity.getPos() << "|" << entity.getSize();   
    } else {
        out << "J" << entity.getPos();
    }
    return out;
};