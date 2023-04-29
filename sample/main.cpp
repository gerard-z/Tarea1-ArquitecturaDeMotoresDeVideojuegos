#include "../source/game_lib.h"
int main()
{
    Grid grid(11);
    std::cout << "inicializando la grilla\n"<< "de 11x11:\n" << grid << std::endl;

    Entity player;
    grid.setEntity(Point{5,0}, player);
    std::cout << "inicializando la grilla con personaje:\n" << grid << std::endl;

    grid.move(player, Point{ 0,1 });
    std::cout << "avanzando personaje:\n" << grid << std::endl;
}