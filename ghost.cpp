#include "ghost.hpp"

Ghost::Ghost()
    : _position{0,0}, _direction(Direction::None), _state(GhostState::Chase), _target{0,0}, _name("") {}

Ghost::Ghost(const char* name, Point startPosition)
    : _position(startPosition), _direction(Direction::None), _state(GhostState::Chase), _target{0,0}, _name(name) {}

Ghost::Ghost(const Ghost& other)
    : _position(other._position), _direction(other._direction), _state(other._state),
      _target(other._target), _name(other._name) {}

Ghost::Ghost(const std::string& name, Point pos, Direction dir, GhostState state, Point target)
    : _name(name), _position(pos), _direction(dir), _state(state), _target(target) {}

Ghost& Ghost::operator=(const Ghost& other) {
    if (this != &other) {
        _position = other._position;
        _direction = other._direction;
        _state = other._state;
        _target = other._target;
        _name = other._name;
    }
    return *this;
}

bool Ghost::operator==(const Ghost& other) const {
    return _position == other._position && _direction == other._direction &&
           _state == other._state && _target == other._target && _name == other._name;
}

bool Ghost::operator!=(const Ghost& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Ghost& g) {
    out << g._name << " " << g._position << " "
        << static_cast<int>(g._direction) << " "
        << static_cast<int>(g._state) << " " << g._target;
    return out;
}

std::istream& operator>>(std::istream& in, Ghost& g) {
    int dir, state;
    Point pos, target;
    std::string name;
    in >> name >> pos >> dir >> state >> target;
    g = Ghost(name, pos, static_cast<Direction>(dir), static_cast<GhostState>(state), target);
    return in;
}

Point Ghost::GetPosition() const { return _position; }
void Ghost::SetPosition(Point pos) { _position = pos; }
Direction Ghost::GetDirection() const { return _direction; }
void Ghost::SetDirection(Direction dir) { _direction = dir; }
GhostState Ghost::GetState() const { return _state; }
void Ghost::SetState(GhostState state) { _state = state; }
Point Ghost::GetTarget() const { return _target; }
void Ghost::SetTarget(Point target) { _target = target; }
const std::string& Ghost::GetName() const { return _name; }

void Ghost::Move() {
    if (_direction == Direction::Up) _position.y--;
    if (_direction == Direction::Down) _position.y++;
    if (_direction == Direction::Left) _position.x--;
    if (_direction == Direction::Right) _position.x++;
}

