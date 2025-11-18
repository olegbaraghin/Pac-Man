#include "pacman.hpp"

#include <iostream>

Pacman::Pacman() : _position{0,0}, _direction(Direction::None), _score(0) {}
Pacman::Pacman(const Point& startPosition) : _position(startPosition), _direction(Direction::None), _score(0) {}

Pacman::Pacman(const Pacman& other)
    : _position(other._position), _direction(other._direction), _score(other._score), _powerMode(other._powerMode), _powerModeTimer(other._powerModeTimer) {}

Pacman& Pacman::operator=(const Pacman& other) {
    if(this != &other) {
        _position = other._position;
        _direction = other._direction;
        _score = other._score;
        _powerMode = other._powerMode;
        _powerModeTimer = other._powerModeTimer;
    }
    return *this;
}

bool Pacman::operator==(const Pacman& other) const {
    return _position == other._position && _direction == other._direction && _score == other._score && _powerMode == other._powerMode;
}

void Pacman::Move(Direction direction) {
    _direction = direction;
    if(direction == Direction::Up) _position.y--;
    if(direction == Direction::Down) _position.y++;
    if(direction == Direction::Left) _position.x--;
    if(direction == Direction::Right) _position.x++;
}

Point Pacman::GetPosition() const { return _position; }

void Pacman::SetPosition(const Point& position) {
    _position = position;
}

Direction Pacman::GetDirection() const {
    return _direction;
}

void Pacman::SetDirection(Direction direction) {
    _direction = direction;
}

void Pacman::Eat(const Pellet& pellet) {
    if(pellet.GetType() == PelletType::Normal) _score += 10;
    else _score += 50;
}

int Pacman::GetScore() const { return _score; }

bool Pacman::IsPowerMode() const { return _powerMode; }

void Pacman::UpdatePowerMode() {
    if(_powerMode && _powerModeTimer > 0) {
        --_powerModeTimer;
        if(_powerModeTimer == 0) _powerMode = false;
    }
}

std::istream& operator>>(std::istream& in, Pacman& pacman) {
    int x,y; int dir; int score; int power;
    in >> x >> y >> dir >> score >> power;
    pacman.SetPosition(Point(x,y));
    pacman.SetDirection(static_cast<Direction>(dir));
    // set score via private member since no setter
    pacman = Pacman(Point(x,y));
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pacman& pacman) {
    out << pacman.GetPosition() << " " << static_cast<int>(pacman.GetDirection()) << " " << pacman.GetScore() << " " << (pacman.IsPowerMode() ? 1 : 0);
    return out;
}
