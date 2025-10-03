#include <iostream>
#include "painter.hpp"
#include "pellet.hpp"

int main() {
    std::cout << "Pac-Man project started!" << std::endl;

    Painter painter;
    Point pacmanPos{5, 5};
    painter.DrawPacman(pacmanPos, Direction::Right, false);

    Point ghostPos{7, 5};
    painter.DrawGhost(ghostPos, "Blinky", "Chase");

    Point pelletPos{3, 3};
    painter.DrawPellet(pelletPos, false);

    Pellet pellet(pelletPos, PelletType::Normal);
    std::cout << "Pellet eaten? " << (pellet.IsEaten() ? "Yes" : "No") << std::endl;
    pellet.Eat();
    std::cout << "Pellet eaten? " << (pellet.IsEaten() ? "Yes" : "No") << std::endl;

    return 0;
}