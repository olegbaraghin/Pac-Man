#include "game_engine.hpp"
#include "painter.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

GameEngine::GameEngine()
    : _pacman(std::make_shared<Pacman>(Point{0, 0})),
      _maze(std::make_shared<Maze>(5, 5)),
      _score(0),
      _gameOver(false)
{
    // seed RNG
    _rng.seed(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    _mouthOpen = false;
    _tickCount = 0;

    _ghosts.emplace_back(std::make_shared<Ghost>("Blinky", Point{1, 1}));

    // create a few pellets at random positions (some power)
    std::uniform_int_distribution<int> distX(0, _maze->GetWidth() - 1);
    std::uniform_int_distribution<int> distY(0, _maze->GetHeight() - 1);
    std::bernoulli_distribution powerChance(0.15); // 15% are power pellets
    for(int i=0;i<6;++i) {
        Point p{distX(_rng), distY(_rng)};
        PelletType t = powerChance(_rng) ? PelletType::Power : PelletType::Normal;
        _pellets.emplace_back(std::make_shared<Pellet>(p, t));
    }
}

void GameEngine::Init() {
    _score = 0;
    _gameOver = false;
    _pacman->SetPosition({0, 0});
    _pacman->SetDirection(Direction::Right);
    _mouthOpen = false;
    _tickCount = 0;

    if (!_ghosts.empty())
        _ghosts.front()->SetPosition({1, 1});

    if (!_pellets.empty())
        ;

    // re-randomize pellet positions and types
    std::uniform_int_distribution<int> distX(0, _maze->GetWidth() - 1);
    std::uniform_int_distribution<int> distY(0, _maze->GetHeight() - 1);
    std::bernoulli_distribution powerChance(0.15);
    for(auto& pellet : _pellets) {
        pellet = std::make_shared<Pellet>(Point{distX(_rng), distY(_rng)}, powerChance(_rng) ? PelletType::Power : PelletType::Normal);
    }
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
    // Occasionally change direction
    std::bernoulli_distribution changeDir(0.20); // 20% chance
    if(changeDir(_rng)) {
        std::uniform_int_distribution<int> dirDist(0, 3);
        Direction d = static_cast<Direction>(dirDist(_rng));
        _pacman->SetDirection(d);
    }

    // Move Pacman with some probability so he doesn't move every tick
    std::bernoulli_distribution moveProb(0.5);
    if(moveProb(_rng)) _pacman->Move(_pacman->GetDirection());

    // toggle mouth occasionally
    if((_tickCount++ % 2) == 0) _mouthOpen = !_mouthOpen;

    // Check pellet collisions
    for(auto& pellet : _pellets) {
        if (!pellet->IsEaten() && pellet->GetPosition() == _pacman->GetPosition()) {
            pellet->Eat();
            _pacman->Eat(*pellet);
            _score = _pacman->GetScore();
            if(pellet->GetType() == PelletType::Power) {
                // enable pacman power mode (simple approach)
                // Pacman has UpdatePowerMode method and internal state; we can approximate
            }
        }
    }

    for(auto& ghost : _ghosts) {
        ghost->Move();

        GhostState st = ghost->GetState();
        if(st == GhostState::Chase) {
            ghost->SetState(GhostState::Scatter);
        } else if(st == GhostState::Scatter) {
            ghost->SetState(GhostState::Frightened);
        } else if(st == GhostState::Frightened) {
            ghost->SetState(GhostState::Eyes);
        } else if(st == GhostState::Eyes) {
            ghost->SetState(GhostState::Chase);
        } else {
            ghost->SetState(GhostState::Chase);
        }
    }
}

void GameEngine::Draw() {
    Painter painter;
    painter.DrawMaze();
    painter.DrawPacman(_pacman->GetPosition(), _pacman->GetDirection(), _mouthOpen);
    for(auto& ghost : _ghosts) {
        std::string stateStr = "Unknown";
        GhostState st = ghost->GetState();
        if(st == GhostState::Chase) stateStr = "Chase";
        else if(st == GhostState::Scatter) stateStr = "Scatter";
        else if(st == GhostState::Frightened) stateStr = "Frightened";
        else if(st == GhostState::Eyes) stateStr = "Eyes";

        painter.DrawGhost(ghost->GetPosition(), ghost->GetName(), stateStr);
    }
    for(auto& pellet : _pellets)
        if(!pellet->IsEaten())
            painter.DrawPellet(pellet->GetPosition(), pellet->GetType() == PelletType::Power);
    std::cout << "Score: " << _score << std::endl;
}

void GameEngine::NextLevel() {
    Init();
}

bool GameEngine::IsGameOver() const {
    return _gameOver;
}

