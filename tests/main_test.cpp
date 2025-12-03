#include <iostream>
#include <cassert>
#include "../include/point.hpp"
#include "../include/pacman.hpp"
#include "../include/ghost.hpp"
#include "../include/maze.hpp"
#include "../include/pellet.hpp"

// Funcție ajutătoare pentru afișarea rezultatelor
void Assert(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "[PASS] " << testName << std::endl;
    } else {
        std::cout << "[FAIL] " << testName << std::endl;
        exit(1); // Oprește testele la prima eroare
    }
}

void TestPoint() {
    Point p1(10, 20);
    Point p2(10, 20);
    Point p3(5, 5);

    Assert(p1.x == 10 && p1.y == 20, "Point Initialization");
    Assert(p1 == p2, "Point Equality");
    Assert(!(p1 == p3), "Point Inequality");
}

void TestPacman() {
    Pacman p(Point(5, 5));
    Assert(p.GetPosition() == Point(5, 5), "Pacman Initialization");
    
    p.Move(Direction::Right);
    Assert(p.GetPosition().x == 6, "Pacman Move Right");
    
    p.Move(Direction::Down);
    Assert(p.GetPosition().y == 6, "Pacman Move Down");

    Assert(p.GetScore() == 0, "Pacman Initial Score");
    
    Pellet pellet(Point(6,6), PelletType::Normal);
    p.Eat(pellet);
    Assert(p.GetScore() == 10, "Pacman Eat Normal Pellet Score");
}

void TestGhost() {
    Ghost g("Blinky", Point(1, 1));
    Assert(g.GetName() == "Blinky", "Ghost Name");
    Assert(g.GetPosition() == Point(1, 1), "Ghost Position");
    
    g.SetState(GhostState::Frightened);
    Assert(g.GetState() == GhostState::Frightened, "Ghost State Change");
}

void TestMaze() {
    Maze m(10, 10);
    Assert(m.GetWidth() == 10, "Maze Width");
    Assert(m.GetHeight() == 10, "Maze Height");
    
    m.SetCell(0, 0, CellType::Wall);
    Assert(m.GetCell(0, 0) == CellType::Wall, "Maze Set/Get Cell");
    
    Assert(!m.IsWalkable(Point(-1, 0)), "Maze Bounds Check Negative");
    Assert(!m.IsWalkable(Point(11, 0)), "Maze Bounds Check Overflow");
}

int main() {
    std::cout << "Running Tests..." << std::endl;
    
    TestPoint();
    TestPacman();
    TestGhost();
    TestMaze();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}