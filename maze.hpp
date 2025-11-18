#pragma once

#include "point.hpp"
#include <vector>
#include <iostream>

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
    Maze();
    Maze(int width, int height);

    Maze(const Maze& other);
    Maze& operator=(const Maze& other);
    bool operator==(const Maze& other) const;

    void LoadFromFile(const char* filename);
    int GetWidth() const;
    int GetHeight() const;
    CellType GetCell(int x, int y) const;
    void SetCell(int x, int y, CellType type);
    bool IsWalkable(Point p) const;
    void Reset();
};

std::istream& operator>>(std::istream& in, Maze& maze);
std::ostream& operator<<(std::ostream& out, const Maze& maze);
