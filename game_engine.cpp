#include "game_engine.hpp"
#include "painter.hpp"
#include <iostream>
#include <algorithm>

GameEngine::GameEngine()
    : _pacman(std::make_shared<Pacman>(Point{0, 0})),
      _maze(std::make_shared<Maze>(5, 5)),
      _score(0),
      _gameOver(false)
{
    _ghosts.emplace_back(std::make_shared<Ghost>("Blinky", Point{1, 1}));
    _pellets.emplace_back(std::make_shared<Pellet>(Point{0, 1}, PelletType::Normal));
}

void GameEngine::Init() {
    _score = 0;
    _gameOver = false;
    _pacman->SetPosition({0, 0});

    if (!_ghosts.empty())
        _ghosts.front()->SetPosition({1, 1});

    if (!_pellets.empty())
        _pellets.front() = std::make_shared<Pellet>(Point{0, 1}, PelletType::Normal);
}

void GameEngine::Run() {
    while (!_gameOver) {
        Update();
        Draw();
        _gameOver = true;
    }
}

void GameEngine::Update() {
    _pacman->Move(_pacman->GetDirection());

    std::for_each(_pellets.begin(), _pellets.end(), [&](auto& pellet) {
        if (!pellet->IsEaten() &&
            pellet->GetPosition() == _pacman->GetPosition()) {
            pellet->Eat();
            _pacman->Eat(*pellet);
            _score = _pacman->GetScore();
        }
    });
}

void GameEngine::Draw() {
    Painter painter;
    painter.DrawMaze();
    painter.DrawPacman(_pacman->GetPosition(), _pacman->GetDirection(), false);

    std::for_each(_ghosts.begin(), _ghosts.end(), [&](const auto& ghost) {
        painter.DrawGhost(ghost->GetPosition(), ghost->GetName(), "Chase");
    });

    std::for_each(_pellets.begin(), _pellets.end(), [&](const auto& pellet) {
        if (!pellet->IsEaten())
            painter.DrawPellet(pellet->GetPosition(), pellet->GetType() == PelletType::Power);
    });

    std::cout << "Score: " << _score << std::endl;
}

void GameEngine::NextLevel() {
    Init();
}

bool GameEngine::IsGameOver() const {
    return _gameOver;
}

