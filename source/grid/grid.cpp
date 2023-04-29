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
};

const std::vector<std::vector<Entity*>>& Grid::getGrid() const
{
    return grid;
}

bool Grid::canMove(const Point &oldPosition, const Point &position)
{
    Entity* entity = getEntity(oldPosition);
    Entity* ptrEntity = getEntity(position);
    if (ptrEntity != nullptr) {
        entity->colision(*ptrEntity);
        return false;
    } else {
        grid[position.y][position.x] = entity;
        grid[oldPosition.y][oldPosition.x] = nullptr;
        return true;
    }
}

void Grid::move(Entity& entity, const Point& direction){
    Point newPos = entity.getPos() + direction;
    if (canMove( entity.getPos(), newPos)){
        entity.setPos(newPos);
    }
}

Entity* Grid::getEntity(const Point &position)
{
    return grid[position.y][position.x];
}

void Grid::setEntity(const Point& position, Entity& entity)
{
    grid[position.y][position.x] = &entity;
    entity.setPos(position);
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