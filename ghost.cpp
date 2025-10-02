#include "ghost.hpp"

Ghost::Ghost() : _position{0,0} {}
Ghost::Ghost(Point startPosition) : _position(startPosition) {}

Point Ghost::GetPosition() const { return _position; }

void Ghost::Move(Direction direction) {
    if(direction == Direction::Up) _position.y--;
    if(direction == Direction::Down) _position.y++;
    if(direction == Direction::Left) _position.x--;
    if(direction == Direction::Right) _position.x++;
}
