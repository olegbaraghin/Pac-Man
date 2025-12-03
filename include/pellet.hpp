/**
 * @file pellet.hpp
 * @brief Definirea clasei Pellet (Pastilă/Punct).
 * @author Student
 * @date 2025
 */

#pragma once
#include "point.hpp"
#include <iostream>

/**
 * @enum PelletType
 * @brief Tipurile de pastile disponibile în joc.
 */
enum class PelletType { 
    Normal = 0, ///< Pastilă obișnuită (oferă puncte standard)
    Power = 1   ///< Pastilă de putere (permite mâncarea fantomelor)
};

/**
 * @class Pellet
 * @brief Reprezintă un obiect colectabil de pe hartă.
 * * Pastilele sunt obiectivele principale ale jocului. Ele au o poziție fixă,
 * un tip anume și o stare (mâncată sau nu).
 */
class Pellet {
    Point _position;    ///< Coordonatele pastilei pe hartă
    PelletType _type;   ///< Tipul pastilei (Normal sau Power)
    bool _eaten;        ///< Flag care indică dacă a fost deja colectată

public:
    /**
     * @brief Constructor implicit.
     */
    Pellet();

    /**
     * @brief Constructor parametrizat.
     * @param position Poziția pastilei.
     * @param type Tipul pastilei (implicit Normal).
     */
    Pellet(const Point& position, PelletType type = PelletType::Normal);
    
    Pellet(const Pellet& other);
    Pellet& operator=(const Pellet& other);
    bool operator==(const Pellet& other) const;

    /**
     * @brief Returnează poziția pastilei.
     * @return Obiect Point cu coordonatele.
     */
    Point GetPosition() const;

    /**
     * @brief Returnează tipul pastilei.
     * @return Valoare din enum-ul PelletType.
     */
    PelletType GetType() const;

    /**
     * @brief Verifică dacă pastila a fost mâncată.
     * @return true dacă este mâncată, false altfel.
     */
    bool IsEaten() const;

    /**
     * @brief Marchează pastila ca fiind mâncată (colectată).
     * Setează flag-ul intern _eaten pe true.
     */
    void Eat();
};

