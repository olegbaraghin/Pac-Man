#include "maze.hpp"

Maze::Maze(int width, int height)
    : _width(width),
      _height(height),
      _grid(height, std::vector<CellType>(width, CellType::Empty))
{}


CellType Maze::GetCell(int x, int y) const { return _grid[y][x]; }
void Maze::SetCell(int x, int y, CellType type) { _grid[y][x] = type; }

bool Maze::IsWalkable(Point p) const {
    if(p.x < 0 || p.y < 0 || p.x >= _width || p.y >= _height) return false;
    return _grid[p.y][p.x] == CellType::Empty;
}
