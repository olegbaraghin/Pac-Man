/**
 * @file pacman.hpp
 * @brief Definirea clasei Pacman care reprezintă jucătorul principal.
 * @author Student
 * @date 2025
 */

#pragma once
#include "point.hpp"
#include "direction.hpp"
#include "pellet.hpp"
#include <iostream>

/**
 * @class Pacman
 * @brief Gestionează starea și comportamentul personajului Pacman.
 * * Această clasă reține poziția curentă, direcția de deplasare,
 * scorul acumulat și starea de "Power Mode".
 */
class Pacman {
    Point _position;        ///< Poziția curentă pe hartă (x, y)
    Direction _direction;   ///< Direcția curentă de deplasare
    int _score;             ///< Scorul curent al jucătorului
    bool _powerMode;        ///< Indică dacă Pacman poate mânca fantome
    int _powerModeTimer;    ///< Timer pentru durata modului Power

public:
    /**
     * @brief Constructor implicit. Inițializează Pacman la (0,0).
     */
    Pacman();

    /**
     * @brief Constructor cu poziție de start.
     * @param startPosition Poziția inițială a lui Pacman.
     */
    Pacman(const Point& startPosition);

    Pacman(const Pacman& other);
    Pacman& operator=(const Pacman& other);
    bool operator==(const Pacman& other) const;

    /**
     * @brief Mută Pacman în direcția specificată.
     * @param dir Noua direcție de deplasare.
     */
    void Move(Direction dir);

    /**
     * @brief Consumă o pastilă și actualizează scorul.
     * @param pellet Pastila care este mâncată.
     */
    void Eat(const Pellet& pellet);

    /**
     * @brief Actualizează timer-ul pentru Power Mode (scade timpul rămas).
     */
    void UpdatePowerMode();

    /**
     * @brief Returnează poziția curentă.
     * @return Obiect de tip Point.
     */
    Point GetPosition() const;

    /**
     * @brief Setează o nouă poziție (teleportare).
     * @param pos Noua poziție.
     */
    void SetPosition(const Point& pos);

    /**
     * @brief Returnează direcția curentă.
     * @return Obiect de tip Direction.
     */
    Direction GetDirection() const;

    /**
     * @brief Schimbă direcția de deplasare.
     * @param dir Noua direcție.
     */
    void SetDirection(Direction dir);

    /**
     * @brief Returnează scorul curent.
     * @return Valoarea scorului (int).
     */
    int GetScore() const;

    /**
     * @brief Verifică dacă Pacman este în Power Mode.
     * @return true dacă este activ, false altfel.
     */
    bool IsPowerMode() const;
};

std::istream& operator>>(std::istream& in, Pacman& pacman);
std::ostream& operator<<(std::ostream& out, const Pacman& pacman);


