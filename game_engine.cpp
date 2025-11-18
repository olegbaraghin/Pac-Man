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
    const int delayIterations = 10000000; 
    while (!_gameOver) {
        Update();
        Draw();

        for(volatile int i = 0; i < delayIterations; ++i) { }
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
    }
    for(auto& ghost : _ghosts) {
        ghost.Move();

        GhostState st = ghost.GetState();
        if(st == GhostState::Chase) {
            ghost.SetState(GhostState::Scatter);
        } else if(st == GhostState::Scatter) {
            ghost.SetState(GhostState::Frightened);
        } else if(st == GhostState::Frightened) {
            ghost.SetState(GhostState::Eyes);
        } else if(st == GhostState::Eyes) {
            ghost.SetState(GhostState::Chase);
        } else {
            ghost.SetState(GhostState::Chase);
        }
    }
}

void GameEngine::Draw() {
    Painter painter;
    painter.DrawMaze();
    painter.DrawPacman(_pacman.GetPosition(), _pacman.GetDirection(), false);
    for(auto& ghost : _ghosts) {
        const char* stateStr = "Unknown";
        GhostState st = ghost.GetState();
        if(st == GhostState::Chase) stateStr = "Chase";
        else if(st == GhostState::Scatter) stateStr = "Scatter";
        else if(st == GhostState::Frightened) stateStr = "Frightened";
        else if(st == GhostState::Eyes) stateStr = "Eyes";

        painter.DrawGhost(ghost.GetPosition(), ghost.GetName().c_str(), stateStr);
    }
    for(auto& pellet : _pellets)
        if(!pellet.IsEaten())
            painter.DrawPellet(pellet.GetPosition(), pellet.GetType() == PelletType::Power);
    std::cout << "Score: " << _score << std::endl;
}

void GameEngine::NextLevel() {
    Init();
}

bool GameEngine::IsGameOver() const {
    return _gameOver;
}

