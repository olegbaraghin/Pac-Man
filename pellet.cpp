#include "pellet.hpp"

Pellet::Pellet() : _position(0, 0), _type(PelletType::Normal), _eaten(false) {}
Pellet::Pellet(const Point& position, PelletType type) : _position(position), _type(type), _eaten(false) {}
Pellet::Pellet(const Pellet& other) : _position(other._position), _type(other._type), _eaten(other._eaten) {}

Point Pellet::GetPosition() const { return _position; }
PelletType Pellet::GetType() const { return _type; }
bool Pellet::IsEaten() const { return _eaten; }
void Pellet::Eat() { _eaten = true; }

Pellet& Pellet::operator=(const Pellet& other) {
    if (this != &other) {
        _position = other._position;
        _type = other._type;
        _eaten = other._eaten;
    }
    return *this;
}

bool Pellet::operator==(const Pellet& other) const {
    return _position == other._position && _type == other._type && _eaten == other._eaten;
}

std::istream& operator>>(std::istream& in, Pellet& pellet) {
    int x, y, ttype, eaten;
    in >> x >> y >> ttype >> eaten;
    pellet = Pellet(Point(x, y), static_cast<PelletType>(ttype));
    if (eaten) pellet.Eat();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pellet& pellet) {
    out << pellet._position << " " << static_cast<int>(pellet._type) << " " << (pellet._eaten ? 1 : 0);
    return out;
}

