#pragma once

#include "point.hpp"
#include "direction.hpp"
#include "pellet.hpp"

class Pacman {
    Point _position;
    Direction _direction;
    int _score;
    bool _powerMode;
    int _powerModeTimer;

public:
    Pacman();
    Pacman(const Point& startPosition);

    void Move(Direction direction);

    Point GetPosition() const;
    void SetPosition(const Point& position);

    Direction GetDirection() const;
    void SetDirection(Direction direction);

    void Eat(const Pellet& pellet);
    int GetScore() const;

    bool IsPowerMode() const;
    void UpdatePowerMode();
};

