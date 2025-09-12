#pragma once

#include "point.hpp"
#include <vector>

enum class CellType {
    Wall,
    Empty,
    Gate,
    Tunnel
};

class Maze {
    int _width;
    int _height;
    std::vector<std::vector<CellType>> _grid;

public:
    Maze(int width, int height);

    void LoadFromFile(const char* filename);

    int GetWidth() const;
    int GetHeight() const;

    CellType GetCell(int x, int y) const;
    void SetCell(int x, int y, CellType type);

    bool IsWalkable(Point p) const;

    void Reset();
};
