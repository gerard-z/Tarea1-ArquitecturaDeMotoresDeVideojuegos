#include "grid.h"

Grid::Grid(const int n)
{
    size = n;
    for (int i=0; i<size; i++)
    {
        std::vector<Entity*> row;
        for (int j=0; j<size; j++)
        {
            row.push_back(nullptr);
        }
        grid.push_back(row);
    }
    boxsize = 2 / (static_cast< float >(n) -5);
    std::cout << "boxsize:" <<boxsize << std::endl;
};

const float Grid::gridToCanvas(const int pos){
    return (2.0f*(static_cast< float >(pos - 2) )/(static_cast< float >(size-5))-1.0f);
}

const float Grid::gridToCanvas(const float pos){
    return ((2*pos - 4.0f )/(static_cast< float >(size-5))-1.0f);
}

const std::vector<std::vector<Entity*>>& Grid::getGrid() const
{
    return grid;
}

bool Grid::canMove(const Point &oldPosition, const Point &position, const Point &position2, BoxRenderer::Canvas& canvas)
{
    Entity* entity = getEntity(oldPosition);

    if (!entity->getType()){
        if (position.x >= size-3 || position.x < 3){
            return false;
        }
        if (position.y >= size-1 || position.y < 3){
            return false;
        }
    }

    Entity* ptrEntity = getEntity(position2);
    if (ptrEntity != nullptr && ptrEntity != entity) {
        entity->colision(*ptrEntity);
        if (entity->getType()){
            moveTo(*ptrEntity, Point{static_cast< float >(size/2), 3}, canvas);
            if (entity->getSize()==3){
                grid[oldPosition.y][oldPosition.x-1] = nullptr;
                grid[oldPosition.y][oldPosition.x] = nullptr;
                grid[oldPosition.y][oldPosition.x+1] = nullptr;
                grid[position.y][position.x-1] = entity;
                grid[position.y][position.x] = entity;
                grid[position.y][position.x+1] = entity;
            } else {
                grid[oldPosition.y][oldPosition.x] = nullptr;
                grid[position.y][position.x] = entity;
            }
            return true;
        } else {
            moveTo(*entity, Point{static_cast< float >(size/2), 2}, canvas);
            return false;
        }
    } else {
        if (entity->getSize()==3){
            grid[oldPosition.y][oldPosition.x-1] = nullptr;
            grid[oldPosition.y][oldPosition.x] = nullptr;
            grid[oldPosition.y][oldPosition.x+1] = nullptr;
            grid[position.y][position.x-1] = entity;
            grid[position.y][position.x] = entity;
            grid[position.y][position.x+1] = entity;
        } else {
            grid[position.y][position.x] = entity;
            grid[oldPosition.y][oldPosition.x] = nullptr;
        }
        return true;
    }
}

void Grid::move(Entity& entity, const Point& direction, BoxRenderer::Canvas& canvas){
    Point newPos = entity.getPos() + direction;
    Point newPos2 = newPos;
    if (entity.getSize() ==3){
        newPos2 = newPos + Point{direction.x};
    }
    if (canMove( entity.getPos(), newPos, newPos2, canvas)){
        entity.setPos(newPos);
        canvas.getBox(entity.getIDBox()).position().x = gridToCanvas(newPos.x);
        canvas.getBox(entity.getIDBox()).position().y = gridToCanvas(newPos.y);
    }
}

void Grid::moveTo(Entity& entity, const Point& destiny, BoxRenderer::Canvas& canvas){
    const Point oldPosition = entity.getPos();
    if (entity.getSize()==3){
        grid[oldPosition.y][oldPosition.x-1] = nullptr;
        grid[oldPosition.y][oldPosition.x] = nullptr;
        grid[oldPosition.y][oldPosition.x+1] = nullptr;
        grid[destiny.y][destiny.x-1] = &entity;
        grid[destiny.y][destiny.x] = &entity;
        grid[destiny.y][destiny.x+1] = &entity;
    } else {
        grid[oldPosition.y][oldPosition.x] = nullptr;
        grid[destiny.y][destiny.x] = &entity;
    }
    entity.setPos(destiny);
    canvas.getBox(entity.getIDBox()).position().x = gridToCanvas(destiny.x);
    canvas.getBox(entity.getIDBox()).position().y = gridToCanvas(destiny.y);
}

Entity* Grid::getEntity(const Point &position)
{
    if (position.x < size && position.x > 0){
        return grid[position.y][position.x];
    } else if (position.x == size) {
        return grid[position.y][size-1];
    } else {
        return grid[position.y][1];
    }
    
}

void Grid::setEntity(const Point& position, Entity& entity)
{
    grid[position.y][position.x] = &entity;
    if (entity.getSize()==3){
        grid[position.y][position.x-1] = &entity;
        grid[position.y][position.x+1] = &entity;
    }
    entity.setPos(position);
    BoxRenderer::Box box = { {gridToCanvas(position.x), gridToCanvas(position.y)}, entity.getColor(), {boxsize * entity.getSize(), boxsize}};
    entity.setBox(box);
}


// Permite obtener la impresión de la entidad, mostrando su ubicación y tamaño.
std::ostream& operator<<(std::ostream& out, const Grid& agrid) {   
    const std::vector<std::vector<Entity*>> grid = agrid.getGrid();
    const int size = grid.size();
    for (int i=size-1; i>=0; i--){
        for (int j=0; j<size; j++){
            if (grid[i][j] == nullptr) {
                out << " " << 0;
            } else {
                out << " " << *grid[i][j];
            }
        }
        out << "\n";
    }
    return out;
};