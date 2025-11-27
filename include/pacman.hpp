#pragma once
#include "point.hpp"
#include "direction.hpp"
#include "pellet.hpp"
#include <iostream>

class Pacman {
    Point _position;
    Direction _direction;
    int _score;
    bool _powerMode;
    int _powerModeTimer;

public:
    Pacman();
    Pacman(const Point& startPosition);

    Pacman(const Pacman& other);
    Pacman& operator=(const Pacman& other);
    bool operator==(const Pacman& other) const;

    void Move(Direction dir);
    void Eat(const Pellet& pellet);
    void UpdatePowerMode();

    Point GetPosition() const;
    void SetPosition(const Point& pos);
    Direction GetDirection() const;
    void SetDirection(Direction dir);
    int GetScore() const;
    bool IsPowerMode() const;
};

std::istream& operator>>(std::istream& in, Pacman& pacman);
std::ostream& operator<<(std::ostream& out, const Pacman& pacman);


