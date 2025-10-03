
#include "pacman.hpp"

Pacman::Pacman() : _position{0,0}, _direction(Direction::None), _score(0) {}
Pacman::Pacman(const Point& startPosition) : _position(startPosition), _direction(Direction::None), _score(0) {}

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

void Pacman::Eat(const Pellet& pellet) {
    if(pellet.GetType() == PelletType::Normal) _score += 10;
    else _score += 50;
}

int Pacman::GetScore() const { return _score; }
