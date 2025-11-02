#pragma once

#include "pacman.hpp"
#include "ghost.hpp"
#include "maze.hpp"
#include "pellet.hpp"
#include <vector>
#include <memory>
#include <algorithm>

class GameEngine {
    std::shared_ptr<Pacman> _pacman;
    std::vector<std::shared_ptr<Ghost>> _ghosts;
    std::shared_ptr<Maze> _maze;
    std::vector<std::shared_ptr<Pellet>> _pellets;
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

