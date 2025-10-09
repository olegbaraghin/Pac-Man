#include <iostream>
#include "painter.hpp"

void Painter::DrawMaze() {
    // Placeholder: In a real game, this would draw the maze grid
    std::cout << "Drawing maze..." << std::endl;
}

void Painter::DrawPacman(Point position, Direction direction, bool powerMode) {
    const char* dirStr = "";
    switch (direction) {
        case Direction::Up: dirStr = "Up"; break;
        case Direction::Down: dirStr = "Down"; break;
        case Direction::Left: dirStr = "Left"; break;
        case Direction::Right: dirStr = "Right"; break;
        default: dirStr = "Unknown"; break;
    }
    std::cout << "Pacman at (" << position.x << "," << position.y << "), direction: " << dirStr << ", powerMode: " << (powerMode ? "ON" : "OFF") << "\n";
}

void Painter::DrawGhost(Point position, const char *ghostName, const char *state) {
    std::cout << "Ghost '" << ghostName << "' (" << state << ") at (" << position.x << "," << position.y << ")\n";
}

void Painter::DrawPellet(Point position, bool isPowerPellet) {
    if (isPowerPellet) {
        std::cout << "Power Pellet at (" << position.x << "," << position.y << ")\n";
    } else {
        std::cout << "Pellet at (" << position.x << "," << position.y << ")\n";
    }
}
