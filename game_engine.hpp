#pragma once

#include "pacman.hpp"
#include "ghost.hpp"
#include "maze.hpp"
#include "pellet.hpp"
#include <vector>

class GameEngine {
    Pacman _pacman;
    std::vector<Ghost> _ghosts;
    Maze _maze;
    std::vector<Pellet> _pellets;
    int _score;
    bool _gameOver;

public:
    GameEngine();

    void Init();

    void Run();

    void Update();

    void Draw();

    void NextLevel();

    bool IsGameOver() const;
};
