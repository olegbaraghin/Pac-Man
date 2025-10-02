#include "pellet.hpp"

Pellet::Pellet() : _position{0,0}, _type(PelletType::Normal), _eaten(false) {}

Pellet::Pellet(Point position, PelletType type) : _position(position), _type(type), _eaten(false) {}

Point Pellet::GetPosition() const { return _position; }
PelletType Pellet::GetType() const { return _type; }
bool Pellet::IsEaten() const { return _eaten; }

void Pellet::Eat() { _eaten = true; }
