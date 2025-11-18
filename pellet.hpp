#pragma once
#include "point.hpp"
#include <iostream>

enum class PelletType { Normal = 0, Power = 1 };

class Pellet {
    Point _position;
    PelletType _type;
    bool _eaten;

public:
    Pellet();
    Pellet(const Point& position, PelletType type = PelletType::Normal);
    Pellet(const Pellet& other);
    Pellet& operator=(const Pellet& other);
    bool operator==(const Pellet& other) const;

    Point GetPosition() const;
    PelletType GetType() const;
    bool IsEaten() const;
    void Eat();
};

