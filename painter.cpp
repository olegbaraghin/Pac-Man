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

void Painter::DrawPellet(Point pos, bool big) {
    std::cout << "Pellet at " << pos << " (Power: " << (big ? "Yes" : "No") << ")" << std::endl;
}

void Painter::DrawImage(Point topLeft, Point bottomRight, const std::vector<std::string>& image) {
    std::cout << "Drawing image from " << topLeft << " to " << bottomRight << std::endl;
    for (const auto& line : image)
        std::cout << line << std::endl;
}

void Painter::WriteText(Point position, const std::string& text) {
    std::cout << "Text at " << position << ": " << text << std::endl;
}

