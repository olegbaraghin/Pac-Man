#include "painter.hpp"
#include <iostream>

void Painter::DrawMaze() {
    std::cout << "Drawing maze..." << std::endl;
}

void Painter::DrawPacman(Point pos, Direction dir, bool mouthOpen) {
    std::string directionStr;
    switch (dir) {
        case Direction::Up: directionStr = "Up"; break;
        case Direction::Down: directionStr = "Down"; break;
        case Direction::Left: directionStr = "Left"; break;
        case Direction::Right: directionStr = "Right"; break;
        default: directionStr = "None"; break;
    }
    std::cout << "Pacman at " << pos << ", direction: " << directionStr
              << ", mouth open: " << (mouthOpen ? "Yes" : "No") << std::endl;
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

