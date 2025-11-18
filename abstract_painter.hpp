#pragma once

#include "point.hpp"

struct AbstractPainter {
    virtual ~AbstractPainter() = default;
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) = 0;
    virtual void WriteText(Point position, const char* text) = 0;
};
