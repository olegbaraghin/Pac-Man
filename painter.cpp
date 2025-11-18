#include "painter.hpp"
#include <iostream>

void Painter::DrawMaze() {
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

void Painter::DrawGhost(Point pos, const std::string& name, const std::string& mode) {
    std::cout << "Ghost '" << name << "' at " << pos << " mode=" << mode << std::endl;
}

void Painter::WriteText(Point position, const char* text) {
    std::cout << "Text at (" << position.x << "," << position.y << "): " << (text ? text : "") << std::endl;
}

void Painter::DrawImage(Point topLeft, Point bottomRight, char** image) {
    std::cout << "Drawing image from (" << topLeft.x << "," << topLeft.y << ") to (" << bottomRight.x << "," << bottomRight.y << ")" << std::endl;
}

void Painter::ClearScreen() {
    // Simple placeholder
    std::cout << std::string(40, '=') << std::endl;
}

