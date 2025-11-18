#pragma once

#include "abstract_painter.hpp"
#include "point.hpp"
#include "direction.hpp"
#include <string>

class Painter : public AbstractPainter {
public:
    Painter() = default;

    // Primary API used across the codebase
    void DrawPacman(Point position, Direction direction, bool powerMode);
    void DrawGhost(Point position, const char* ghostName, const char* state);
    void DrawPellet(Point position, bool isPowerPellet);
    void DrawMaze();

    void WriteText(Point position, const char* text) override;
    void ClearScreen();

    // Additional convenience overloads implemented in .cpp
    void DrawGhost(Point pos, const std::string& name, const std::string& mode);

    // AbstractPainter implementation
    void DrawImage(Point topLeft, Point bottomRight, char** image) override;
};

