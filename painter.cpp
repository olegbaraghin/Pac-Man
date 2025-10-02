#include "painter.hpp"

void Painter::DrawPacman(Point position) {
    std::cout << "Pacman at (" << position.x << "," << position.y << ")\n";
}

void Painter::DrawGhost(Point position) {
    std::cout << "Ghost at (" << position.x << "," << position.y << ")\n";
}

void Painter::DrawPellet(Point position) {
    std::cout << "Pellet at (" << position.x << "," << position.y << ")\n";
}
