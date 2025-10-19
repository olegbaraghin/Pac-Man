#include <iostream>
#include "painter.hpp"

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

void Painter::DrawPacman(Point pos, Direction dir, bool mouthOpen) {
    std::string d;
    switch (dir) {
        case Direction::Up: d = "Up"; break;
        case Direction::Down: d = "Down"; break;
        case Direction::Left: d = "Left"; break;
        case Direction::Right: d = "Right"; break;
    }
    std::cout << "DrawPacman at " << pos << " dir=" << d << " mouthOpen=" << (mouthOpen ? "Yes" : "No") << std::endl;
}

void Painter::DrawGhost(Point position, const char *ghostName, const char *state) {
    std::cout << "Ghost '" << ghostName << "' (" << state << ") at (" << position.x << "," << position.y << ")\n";
}

void Painter::DrawGhost(Point pos, const std::string& name, const std::string& mode) {
    std::cout << "DrawGhost '" << name << "' at " << pos << " mode=" << mode << std::endl;
}

void Painter::DrawPellet(Point position, bool isPowerPellet) {
    if (isPowerPellet) {
        std::cout << "Power Pellet at (" << position.x << "," << position.y << ")\n";
    } else {
        std::cout << "Pellet at (" << position.x << "," << position.y << ")\n";
    }
}

void Painter::DrawPellet(Point pos, bool big) {
    std::cout << "DrawPellet at " << pos << " big=" << (big ? "Yes" : "No") << std::endl;
}

void Painter::DrawImage(Point topLeft, Point bottomRight, char** image) {
    std::cout << "DrawImage from " << topLeft << " to " << bottomRight << std::endl;
}

void Painter::WriteText(Point position, char* text) {
    std::cout << "WriteText at " << position << ": " << (text ? text : "") << std::endl;
}
