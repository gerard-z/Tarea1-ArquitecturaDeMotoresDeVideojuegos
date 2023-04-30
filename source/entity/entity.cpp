#include "entity.h"


Entity::Entity(const int size, const float velocity, const Point& Aposition, const BoxRenderer::Color Acolor, const BoxRenderer::Box Abox)
{
    _sizeX = size;
    _velocity = velocity;
    position = Aposition;
    color = Acolor;
    box = Abox;
}

Entity::Entity()
{
    _sizeX = 1;
    _velocity = 1;
    position = Point{ 0,0 };
    isCar = false;
    color = BoxRenderer::Color::Green();
    box = BoxRenderer::Box{ {0,0}, color, {1,1} };
}

Entity::Entity(const int size, const float velocity, const BoxRenderer::Color Acolor)
{
    _sizeX = size;
    _velocity = velocity;
    position = Point{ 0,0 };
    color = Acolor;
}

void Entity::colision(Entity &entity)
{
    std::cout << "Colisión de" << *this << " con " << entity << std::endl;
}

const bool Entity::getType(){
    return isCar;
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

BoxRenderer::Color& Entity::getColor(){
    return color;
}

void Entity::setColor(const BoxRenderer::Color acolor){
    color = acolor;
}

BoxRenderer::Box& Entity::getBox(){
    return box;
}

void Entity::setBox(const BoxRenderer::Box& abox){
    box = abox;
}

void Entity::setBox(const BoxRenderer::BoxId aID, BoxRenderer::Canvas& canvas){
    setIDBox(aID);
    setBox(canvas.getBox(aID));
}

BoxRenderer::BoxId& Entity::getIDBox(){
    return idBox;
}

void Entity::setIDBox(const BoxRenderer::BoxId aID){
    idBox = aID;
}

std::ostream& operator<<(std::ostream& out, const Entity& entity) {
    if (entity.isCar){
        out << "V" << entity.getPos() << "|" << entity.getSize();   
    } else {
        out << "J" << entity.getPos();
    }
    return out;
};