#include "maze.hpp"
#include <fstream>

Maze::Maze(int width, int height)
    : _width(width), _height(height), _grid(height, std::vector<CellType>(width, CellType::Empty)) {}

Maze::Maze(const Maze& other)
    : _width(other._width), _height(other._height), _grid(other._grid) {}

Maze& Maze::operator=(const Maze& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        _grid = other._grid;
    }
    return *this;
}

bool Maze::operator==(const Maze& other) const {
    return _width == other._width && _height == other._height && _grid == other._grid;
}

bool Maze::operator!=(const Maze& other) const {
    return !(*this == other);
}

void Maze::LoadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;
    file >> *this;
}

int Maze::GetWidth() const { return _width; }
int Maze::GetHeight() const { return _height; }
CellType Maze::GetCell(int x, int y) const { return _grid[y][x]; }
void Maze::SetCell(int x, int y, CellType type) { _grid[y][x] = type; }

bool Maze::IsWalkable(Point p) const {
    if (p.x < 0 || p.y < 0 || p.x >= _width || p.y >= _height)
        return false;
    return _grid[p.y][p.x] != CellType::Wall;
}

std::ostream& operator<<(std::ostream& os, const Maze& maze) {
    os << maze._width << " " << maze._height << "\n";
    for (const auto& row : maze._grid) {
        for (auto cell : row)
            os << static_cast<int>(cell) << " ";
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Maze& maze) {
    is >> maze._width >> maze._height;
    maze._grid.resize(maze._height, std::vector<CellType>(maze._width));
    for (int y = 0; y < maze._height; ++y)
        for (int x = 0; x < maze._width; ++x) {
            int c;
            is >> c;
            maze._grid[y][x] = static_cast<CellType>(c);
        }
    return is;
}


