
#include "ghost.hpp"

Ghost::Ghost() : _position{0,0}, _direction(Direction::None), _state(GhostState::Chase), _target{0,0}, _name("") {}
Ghost::Ghost(const char* name, Point startPosition) : _position(startPosition), _direction(Direction::None), _state(GhostState::Chase), _target{0,0}, _name(name) {}

Point Ghost::GetPosition() const { return _position; }

void Ghost::SetPosition(Point pos) {
    _position = pos;
}

void Ghost::Move() {
    if(_direction == Direction::Up) _position.y--;
    if(_direction == Direction::Down) _position.y++;
    if(_direction == Direction::Left) _position.x--;
    if(_direction == Direction::Right) _position.x++;
}

Direction Ghost::GetDirection() const { return _direction; }

void Ghost::SetDirection(Direction dir) {
    _direction = dir;
}

GhostState Ghost::GetState() const { return _state; }

void Ghost::SetState(GhostState state) {
    _state = state;
}

Point Ghost::GetTarget() const { return _target; }

void Ghost::SetTarget(Point target) {
    _target = target;
}

const char* Ghost::GetName() const { return _name; }
