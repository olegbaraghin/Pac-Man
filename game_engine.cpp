#include "game_engine.hpp"
#include "painter.hpp"
#include <iostream>

GameEngine::GameEngine()
    : _pacman({0,0}), _maze(5,5), _score(0), _gameOver(false)
{
    _ghosts.push_back(Ghost("Blinky", {1,1}));
    _pellets.push_back(Pellet({0,1}, PelletType::Normal));
}

void GameEngine::Init() {
    _score = 0;
    _gameOver = false;
    _pacman.SetPosition({0,0});
    if(!_ghosts.empty())
        _ghosts[0].SetPosition({1,1});
    if(!_pellets.empty())
        _pellets[0] = Pellet({0,1}, PelletType::Normal);
}

void GameEngine::Run() {
    while (!_gameOver) {
        Update();
        Draw();
        _gameOver = true;
    }
}

void GameEngine::Update() {
    _pacman.Move(_pacman.GetDirection());
    for(auto& pellet : _pellets) {
        if(!pellet.IsEaten() &&
           pellet.GetPosition().x == _pacman.GetPosition().x &&
           pellet.GetPosition().y == _pacman.GetPosition().y)
        {
            pellet.Eat();
            _pacman.Eat(pellet);
            _score = _pacman.GetScore();
        }
    }
    for(auto& ghost : _ghosts) {
    }
}

void GameEngine::Draw() {
    Painter painter;
    painter.DrawMaze();
    painter.DrawPacman(_pacman.GetPosition(), _pacman.GetDirection(), false);
    for(auto& ghost : _ghosts)
        painter.DrawGhost(ghost.GetPosition(), "Ghost", "Chase");
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
