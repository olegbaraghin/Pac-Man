#pragma once

#include "point.hpp"
#include "direction.hpp"

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
    const char* _name;

public:
    Ghost();
    Ghost(const char* name, Point startPosition);

    Point GetPosition() const;
    void SetPosition(Point pos);
    Direction GetDirection() const;
    void SetDirection(Direction dir);

    GhostState GetState() const;
    void SetState(GhostState state);
    Point GetTarget() const;
    void SetTarget(Point target);

    void Move();

    const char* GetName() const;
};
