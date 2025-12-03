/**
 * @file ghost.hpp
 * @brief Definirea clasei Ghost (Fantoma).
 * @author Student
 * @date 2025
 */

#pragma once
#include "point.hpp"
#include "direction.hpp"
#include <string>
#include <iostream>

/**
 * @enum GhostState
 * @brief Stările posibile ale unei fantome.
 */
enum class GhostState {
    Chase,      ///< Urmărește Pacman
    Scatter,    ///< Se retrage în colțul său
    Frightened, ///< Fuge de Pacman (când Power Mode este activ)
    Eyes        ///< A fost mâncată, se întoarce la bază
};

/**
 * @class Ghost
 * @brief Reprezintă un inamic în joc.
 */
class Ghost {
    Point _position;
    Direction _direction;
    GhostState _state;
    Point _target;
    std::string _name;

public:
    Ghost();
    
    /**
     * @brief Constructor cu nume și poziție.
     * @param name Numele fantomei (ex: "Blinky").
     * @param startPosition Poziția de start.
     */
    Ghost(const std::string& name, Point startPosition);
    
    Ghost(const Ghost& other);
    Ghost& operator=(const Ghost& other);
    bool operator==(const Ghost& other) const;
    bool operator!=(const Ghost& other) const;

    Point GetPosition() const;
    void SetPosition(Point pos);

    Direction GetDirection() const;
    void SetDirection(Direction dir);

    GhostState GetState() const;
    void SetState(GhostState state);

    Point GetTarget() const;
    void SetTarget(Point target);

    /**
     * @brief Execută logica de mișcare a fantomei bazată pe stare și țintă.
     */
    void Move();

    void SetName(const std::string& name);
    const std::string& GetName() const;

    friend std::ostream& operator<<(std::ostream& out, const Ghost& g);
    friend std::istream& operator>>(std::istream& in, Ghost& g);
};

std::istream& operator>>(std::istream& in, Ghost& ghost);
std::ostream& operator<<(std::ostream& out, const Ghost& ghost);
