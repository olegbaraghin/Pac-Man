#pragma once

#include "point.hpp"

enum class PelletType {
    Normal,
    Power
};

class Pellet {
    Point _position;
    PelletType _type;
    bool _eaten;

public:
    Pellet();
    Pellet(Point position, PelletType type);

    Point GetPosition() const;
    PelletType GetType() const;
    bool IsEaten() const;

    void Eat();
};
