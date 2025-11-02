#pragma once

#include "abstract_painter.hpp"
#include "point.hpp"
#include <string>
#include <iostream>

enum class Direction { None, Up, Down, Left, Right };

class Painter : public AbstractPainter {
public:
    Painter() = default;

    void DrawMaze();
    void DrawPacman(Point pos, Direction dir, bool mouthOpen);
    void DrawGhost(Point pos, const std::string& name, const std::string& mode);
    void DrawPellet(Point pos, bool big);

    void DrawImage(Point topLeft, Point bottomRight, const std::vector<std::string>& image);
    void WriteText(Point position, const std::string& text);
};

