
#include "ghost.hpp"

Ghost::Ghost() : _position{0,0}, _direction(Direction::None), _state(GhostState::Chase), _target{0,0}, _name("") {}
Ghost::Ghost(const char* name, Point startPosition) : _position(startPosition), _direction(Direction::None), _state(GhostState::Chase), _target{0,0}, _name(name) {}

Point Ghost::GetPosition() const { return _position; }

void Ghost::SetPosition(Point pos) {
    _position = pos;
}

void Ghost::Move() {
    // Example movement logic: move in the current direction
    if(_direction == Direction::Up) _position.y--;
    if(_direction == Direction::Down) _position.y++;
    if(_direction == Direction::Left) _position.x--;
    if(_direction == Direction::Right) _position.x++;
}
