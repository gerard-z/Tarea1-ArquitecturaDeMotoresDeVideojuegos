#include "../source/game_lib.h"
int main()
{
    Grid grid(17);
    //std::cout << "inicializando la grilla\n"<< "de 11x11:\n" << grid << std::endl;

    Entity player;
    grid.setEntity(Point{9,3}, player);
    //std::cout << "inicializando la grilla con personaje:\n" << grid << std::endl;

    // grid.move(player, Point{ 0,1 });
    //std::cout << "avanzando personaje:\n" << grid << std::endl;

    Entity car(3, 2, BoxRenderer::Color::Blue());
    grid.setEntity(Point{ 1,8 }, car);

    Entity car1(3, 2, BoxRenderer::Color::Blue());
    grid.setEntity(Point{ 8,8 }, car1);

    Entity car2(1, 2, BoxRenderer::Color::Red());
    grid.setEntity(Point{ 15,5 }, car2);

    Entity car22(1, 2, BoxRenderer::Color::Red());
    grid.setEntity(Point{ 11,5 }, car22);

    Entity car3(1, 2, BoxRenderer::Color::Yellow());
    grid.setEntity(Point{ 15,10 }, car3);

    Entity car32(1, 2, BoxRenderer::Color::Yellow());
    grid.setEntity(Point{ 13,10 }, car32);

    Entity car33(1, 2, BoxRenderer::Color::Yellow());
    grid.setEntity(Point{ 11,10 }, car33);

    Entity car4(3, 2, BoxRenderer::Color::Gray());
    grid.setEntity(Point{ 1,12 }, car4);



    // settings
    constexpr unsigned int SCR_WIDTH = 600;
    constexpr unsigned int SCR_HEIGHT = 600;

    BoxRenderer::Canvas canvas(SCR_WIDTH, SCR_HEIGHT, "Frogger");

    canvas.setBackgroundColor(BoxRenderer::Color::Black());

    BoxRenderer::BoxId idboxPlayer = canvas.addBox(player.getBox());
    player.setBox(idboxPlayer, canvas);

    BoxRenderer::BoxId idboxCar = canvas.addBox(car.getBox());
    car.setBox(idboxCar, canvas);

    idboxCar = canvas.addBox(car1.getBox());
    car1.setBox(idboxCar, canvas);

    idboxCar = canvas.addBox(car2.getBox());
    car2.setBox(idboxCar, canvas);

    idboxCar = canvas.addBox(car22.getBox());
    car22.setBox(idboxCar, canvas);

    idboxCar = canvas.addBox(car3.getBox());
    car3.setBox(idboxCar, canvas);

    idboxCar = canvas.addBox(car32.getBox());
    car32.setBox(idboxCar, canvas);

    idboxCar = canvas.addBox(car33.getBox());
    car33.setBox(idboxCar, canvas);

    idboxCar = canvas.addBox(car4.getBox());
    car4.setBox(idboxCar, canvas);

    float time1= 0.0f;
    float time2= 0.0f;
    float time3= 0.0f;
    float time4= 0.0f;
    bool win = false;

    auto update = [&](float dt)
    {
        time1+=dt;
        time2+=dt;
        time3+=dt;
        time4+=dt;

        if (player.getPos().y == 15) {
            std::cout << "YOU WIN" << std::endl;
            win = true;
            time1 = 0.0f;
        }

        if (!win) {
            if (time1 > 600.0f) {
                time1 = 0.0f;
                if (car.getPos().x == 15) {
                    grid.move(car, Point{ -14.0f, 0.0f }, canvas);
                } else {
                    grid.move(car, Point{ 1.0f,0.0f }, canvas);
                }
                if (car1.getPos().x == 15) {
                    grid.move(car1, Point{ -14.0f, 0.0f }, canvas);
                } else {
                    grid.move(car1, Point{ 1.0f,0.0f }, canvas);
                }
            }

            if (time2 > 800.0f) {
                time2 = 0.0f;
                grid.move(car2, Point{ -1.0f,0.0f }, canvas);
                grid.move(car22, Point{ -1.0f,0.0f }, canvas);
                if (car2.getPos().x == 1) {
                    grid.move(car2, Point{ 15.0f, 0.0f }, canvas);
                }
                if (car22.getPos().x == 1) {
                    grid.move(car22, Point{ 15.0f, 0.0f }, canvas);
                }
            }

            if (time3 > 350.0f) {
                time3 = 0.0f;
                grid.move(car3, Point{ -1.0f,0.0f }, canvas);
                grid.move(car32, Point{ -1.0f,0.0f }, canvas);
                grid.move(car33, Point{ -1.0f,0.0f }, canvas);
                if (car3.getPos().x == 1) {
                    grid.move(car3, Point{ 15.0f, 0.0f }, canvas);
                }
                if (car32.getPos().x == 1) {
                    grid.move(car32, Point{ 15.0f, 0.0f }, canvas);
                }
                if (car33.getPos().x == 1) {
                    grid.move(car33, Point{ 15.0f, 0.0f }, canvas);
                }
            }

            if (time4 > 200.0f) {
                time4 = 0.0f;
                 if (car4.getPos().x == 15) {
                     grid.move(car4, Point{ -14.0f, 0.0f }, canvas);
                 } else {
                     grid.move(car4, Point{ 1.0f,0.0f }, canvas);
                 }
            }

        } else if (time1 > 3000.0f) {
            win = false;
            grid.moveTo(player, Point{9, 3}, canvas);
        }
    };

    Alice::Controller controller;
    controller.onKeyPress(Alice::Key::UP, [&]() { grid.move(player, Point{ 0.0f, 1.0f }, canvas); });
    controller.onKeyPress(Alice::Key::LEFT, [&]() { grid.move(player, Point{ -1.0f, 0.0f }, canvas); });
    controller.onKeyPress(Alice::Key::DOWN, [&]() { grid.move(player, Point{ 0.0f, -1.0f }, canvas); });
    controller.onKeyPress(Alice::Key::RIGHT, [&]() { grid.move(player, Point{ 1.0f, 0.0f }, canvas); });
    controller.onKeyPress(Alice::Key::ESCAPE, [&]() { canvas.close(); });

    canvas.drawScene(controller, update); //runScene
    
    return 0;
}