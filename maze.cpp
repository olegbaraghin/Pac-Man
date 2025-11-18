#include "maze.hpp"

#include <iostream>

Maze::Maze(int width, int height)
    : _width(width),
      _height(height),
      _grid(height, std::vector<CellType>(width, CellType::Empty))
{}

Maze::Maze() : _width(0), _height(0), _grid() {}

Maze::Maze(const Maze& other) : _width(other._width), _height(other._height), _grid(other._grid) {}

Maze& Maze::operator=(const Maze& other) {
    if(this != &other) {
        _width = other._width;
        _height = other._height;
        _grid = other._grid;
    }
    return *this;
}

bool Maze::operator==(const Maze& other) const {
    return _width == other._width && _height == other._height && _grid == other._grid;
}

std::istream& operator>>(std::istream& in, Maze& maze) {
    int w,h; in >> w >> h;
    maze = Maze(w,h);
    for(int y=0;y<h;++y){
        for(int x=0;x<w;++x){
            int cell; in >> cell;
            maze.SetCell(x,y, static_cast<CellType>(cell));
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Maze& maze) {
    out << maze.GetWidth() << " " << maze.GetHeight() << "\n";
    for(int y=0;y<maze.GetHeight();++y){
        for(int x=0;x<maze.GetWidth();++x){
            out << static_cast<int>(maze.GetCell(x,y)) << (x+1==maze.GetWidth()?"":" ");
        }
        out << "\n";
    }
    return out;
}


CellType Maze::GetCell(int x, int y) const { return _grid[y][x]; }
void Maze::SetCell(int x, int y, CellType type) { _grid[y][x] = type; }

bool Maze::IsWalkable(Point p) const {
    if(p.x < 0 || p.y < 0 || p.x >= _width || p.y >= _height) return false;
    return _grid[p.y][p.x] == CellType::Empty;
}

int Maze::GetWidth() const { return _width; }
int Maze::GetHeight() const { return _height; }

void Maze::Reset() {
    _grid.assign(_height, std::vector<CellType>(_width, CellType::Empty));
}
