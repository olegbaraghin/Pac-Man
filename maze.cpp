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
    return _width == other._width &&
           _height == other._height &&
           _grid == other._grid;
}

bool Maze::operator!=(const Maze& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Maze& maze) {
    os << maze._width << " " << maze._height << "\n";
    for (const auto& row : maze._grid) {
        for (const auto& cell : row) {
            os << static_cast<int>(cell) << " ";
        }
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Maze& maze) {
    is >> maze._width >> maze._height;
    maze._grid.resize(maze._height, std::vector<CellType>(maze._width));
    for (int y = 0; y < maze._height; ++y) {
        for (int x = 0; x < maze._width; ++x) {
            int cell;
            is >> cell;
            maze._grid[y][x] = static_cast<CellType>(cell);
        }
    }
    return is;
}

