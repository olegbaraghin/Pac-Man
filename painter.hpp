#pragma once

#include "point.hpp"
#include "direction.hpp"

class Painter {
public:
    void DrawPacman(Point position, Direction direction, bool powerMode);

    void DrawGhost(Point position, const char* ghostName, const char* state);

    void DrawPellet(Point position, bool isPowerPellet);

    void DrawMaze();

    void WriteText(Point position, const char* text);

    void ClearScreen();
};
