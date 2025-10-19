#include "pacman.hpp"

Pacman::Pacman()
    : _position{0,0}, _direction(Direction::None), _score(0), _powerMode(false), _powerModeTimer(0) {}

Pacman::Pacman(const Point& startPosition)
    : _position(startPosition), _direction(Direction::None), _score(0), _powerMode(false), _powerModeTimer(0) {}

Pacman::Pacman(const Pacman& other)
    : _position(other._position), _direction(other._direction), _score(other._score),
      _powerMode(other._powerMode), _powerModeTimer(other._powerModeTimer) {}

Pacman::Pacman(const Point& pos, Direction dir, int score, bool powerMode, int powerTimer)
    : _position(pos), _direction(dir), _score(score), _powerMode(powerMode), _powerModeTimer(powerTimer) {}

Pacman& Pacman::operator=(const Pacman& other) {
    if (this != &other) {
        _position = other._position;
        _direction = other._direction;
        _score = other._score;
        _powerMode = other._powerMode;
        _powerModeTimer = other._powerModeTimer;
    }
    return *this;
}

bool Pacman::operator==(const Pacman& other) const {
    return _position == other._position && _direction == other._direction &&
           _score == other._score && _powerMode == other._powerMode &&
           _powerModeTimer == other._powerModeTimer;
}

bool Pacman::operator!=(const Pacman& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Pacman& p) {
    out << p._position << " " << static_cast<int>(p._direction) << " "
        << p._score << " " << p._powerMode << " " << p._powerModeTimer;
    return out;
}

std::istream& operator>>(std::istream& in, Pacman& p) {
    int dir, score, powerTimer;
    bool power;
    in >> p._position >> dir >> score >> power >> powerTimer;
    p._direction = static_cast<Direction>(dir);
    p._score = score;
    p._powerMode = power;
    p._powerModeTimer = powerTimer;
    return in;
}

