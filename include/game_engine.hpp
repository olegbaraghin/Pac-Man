/**
 * @file game_engine.hpp
 * @brief Definirea motorului principal al jocului.
 * @author Student
 * @date 2025
 */

#pragma once

#include "pacman.hpp"
#include "ghost.hpp"
#include "maze.hpp"
#include "pellet.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

/**
 * @class GameEngine
 * @brief Gestionează logica centrală și bucla jocului.
 * * Această clasă coordonează interacțiunile dintre Pacman, fantome,
 * labirint și pastile. Se ocupă de actualizarea stării (Update) 
 * și de afișare (Draw).
 */
class GameEngine {
    std::shared_ptr<Pacman> _pacman;            ///< Pointer către jucător
    std::vector<std::shared_ptr<Ghost>> _ghosts;///< Lista de fantome
    std::shared_ptr<Maze> _maze;                ///< Harta jocului
    std::vector<std::shared_ptr<Pellet>> _pellets; ///< Lista de pastile
    int _score;                                 ///< Scorul global al sesiunii
    bool _gameOver;                             ///< Starea jocului (terminat sau nu)
    std::mt19937 _rng;                          ///< Generator de numere aleatoare
    bool _mouthOpen;                            ///< Stare vizuală pentru animația gurii
    int _tickCount;                             ///< Contor pentru cadre (frame-uri)

public:
    /**
     * @brief Constructor. Inițializează resursele și entitățile jocului.
     */
    GameEngine();

    /**
     * @brief Resetează starea jocului pentru o nouă sesiune sau nivel.
     * Repozitionează entitățile și resetează scorul/flag-urile.
     */
    void Init();

    /**
     * @brief Pornește bucla principală a jocului (Game Loop).
     * Rulează atâta timp cât _gameOver este false.
     */
    void Run();

    /**
     * @brief Actualizează logica jocului (un pas de simulare).
     * Gestionează mișcarea, coliziunile și inteligența artificială a fantomelor.
     */
    void Update();

    /**
     * @brief Randează starea curentă a jocului.
     * Apelează metodele din clasa Painter pentru afișare.
     */
    void Draw();

    /**
     * @brief Pregătește trecerea la nivelul următor.
     * (Momentan reinițializează nivelul curent).
     */
    void NextLevel();

    /**
     * @brief Verifică dacă jocul s-a terminat.
     * @return true dacă jocul este "Game Over", false altfel.
     */
    bool IsGameOver() const;
};

