#pragma once

#include "abstract_painter.hpp"
#include "point.hpp"
#include "direction.hpp"
#include <string>
#include <vector>

class Painter : public AbstractPainter {
public:
    Painter() = default;

    // Primary API used across the codebase
    void DrawPacman(Point position, Direction direction, bool powerMode);
    void DrawGhost(Point position, const std::string& ghostName, const std::string& state);
    void DrawPellet(Point position, bool isPowerPellet);
    void DrawMaze();

    void WriteText(Point position, const std::string& text) override;
    void ClearScreen();

    // Additional convenience helpers implemented in .cpp

    // AbstractPainter implementation
    void DrawImage(Point topLeft, Point bottomRight, const std::vector<std::string>& image) override;
};

