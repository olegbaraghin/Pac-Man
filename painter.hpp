#pragma once

#include "abstract_painter.hpp"
#include "point.hpp"
#include <string>
#include <iostream>

enum class Direction { Up, Down, Left, Right };

class Painter : public AbstractPainter {
public:
    Painter() = default;

    void DrawPacman(Point pos, Direction dir, bool mouthOpen);
    void DrawGhost(Point pos, const std::string& name, const std::string& mode);
    void DrawPellet(Point pos, bool big);

    void DrawImage(Point topLeft, Point bottomRight, char** image) override;
    void WriteText(Point position, char* text) override;
};
