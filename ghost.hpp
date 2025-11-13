#pragma once

#include "point.hpp"
#include "direction.hpp"
#include <iostream>
#include <memory>
#include <string>

enum class GhostState {
    Chase,
    Scatter,
    Frightened,
    Eyes
};

class Ghost {
    Point _position;
    Direction _direction;
    GhostState _state;
    Point _target;
    std::string _name;

public:
    Ghost();
    Ghost(const std::string& name, Point startPosition);
    Ghost(const Ghost& other);
    Ghost(const std::string& name, Point pos, Direction dir, GhostState state, Point target);

    Ghost& operator=(const Ghost& other);
    bool operator==(const Ghost& other) const;
    bool operator!=(const Ghost& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Ghost& g);
    friend std::istream& operator>>(std::istream& in, Ghost& g);

    void Move();

    Point GetPosition() const;
    void SetPosition(Point pos);

    Direction GetDirection() const;
    void SetDirection(Direction dir);

    GhostState GetState() const;
    void SetState(GhostState state);

    Point GetTarget() const;
    void SetTarget(Point target);

    const std::string& GetName() const;
};

