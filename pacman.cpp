#include "pacman.hpp"

Pacman::Pacman()
    : _position{0,0}, _direction(Direction::None), _score(0), _powerMode(false), _powerModeTimer(0) {}

Pacman::Pacman(const Point& startPosition)
    : _position(startPosition), _direction(Direction::None), _score(0), _powerMode(false), _powerModeTimer(0) {}

Pacman::Pacman(const Pacman& other)
    : _position(other._position), _direction(other._direction),
      _score(other._score), _powerMode(other._powerMode), _powerModeTimer(other._powerModeTimer) {}

Pacman::Pacman(const Point& pos, Direction dir, int score, bool powerMode, int timer)
    : _position(pos), _direction(dir), _score(score), _powerMode(powerMode), _powerModeTimer(timer) {}

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
    int dir, score, timer;
    bool power;
    in >> p._position >> dir >> score >> power >> timer;
    p._direction = static_cast<Direction>(dir);
    p._score = score;
    p._powerMode = power;
    p._powerModeTimer = timer;
    return in;
}

void Pacman::Move(Direction dir) {
    _direction = dir;
    switch (dir) {
        case Direction::Up: _position.y--; break;
        case Direction::Down: _position.y++; break;
        case Direction::Left: _position.x--; break;
        case Direction::Right: _position.x++; break;
        default: break;
    }
}

void Pacman::Eat(const Pellet& pellet) {
    if (!pellet.IsEaten()) {
        _score += (pellet.GetType() == PelletType::Power ? 50 : 10);
        if (pellet.GetType() == PelletType::Power) {
            _powerMode = true;
            _powerModeTimer = 100;
        }
    }
}

void Pacman::UpdatePowerMode() {
    if (_powerMode && _powerModeTimer > 0)
        _powerModeTimer--;
    else
        _powerMode = false;
}

Point Pacman::GetPosition() const { return _position; }
void Pacman::SetPosition(const Point& pos) { _position = pos; }
Direction Pacman::GetDirection() const { return _direction; }
void Pacman::SetDirection(Direction dir) { _direction = dir; }
int Pacman::GetScore() const { return _score; }
bool Pacman::IsPowerMode() const { return _powerMode; }


