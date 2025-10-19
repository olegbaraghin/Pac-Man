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
    Pacman(const Point& position, Direction dir, int score, bool powerMode, int powerTimer);

    Pacman& operator=(const Pacman& other);
    bool operator==(const Pacman& other) const;
    bool operator!=(const Pacman& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Pacman& p);
    friend std::istream& operator>>(std::istream& in, Pacman& p);

    void Move(Direction direction);
    void Eat(const Pellet& pellet);
    void UpdatePowerMode();

    Point GetPosition() const;
    void SetPosition(const Point& position);

    Direction GetDirection() const;
    void SetDirection(Direction direction);

    int GetScore() const;
    bool IsPowerMode() const;
};


