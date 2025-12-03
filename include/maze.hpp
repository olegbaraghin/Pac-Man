/**
 * @file maze.hpp
 * @brief Gestionează harta jocului (Labirintul).
 * @author Student
 * @date 2025
 */

#pragma once
#include "point.hpp"
#include <vector>
#include <iostream>

/**
 * @enum CellType
 * @brief Tipurile de celule din labirint.
 */
enum class CellType { Wall, Empty, Gate, Tunnel };

/**
 * @class Maze
 * @brief Reprezintă structura grilei de joc.
 */
class Maze {
    int _width;
    int _height;
    std::vector<std::vector<CellType>> _grid;

public:
    Maze();
    Maze(int width, int height);

    Maze(const Maze& other);
    Maze& operator=(const Maze& other);
    bool operator==(const Maze& other) const;

    /**
     * @brief Încarcă structura labirintului dintr-un fișier text.
     * @param filename Calea către fișier.
     */
    void LoadFromFile(const std::string& filename);

    int GetWidth() const;
    int GetHeight() const;

    /**
     * @brief Returnează tipul celulei de la coordonatele date.
     * @param x Coordonata X.
     * @param y Coordonata Y.
     * @return Tipul celulei (CellType).
     */
    CellType GetCell(int x, int y) const;
    void SetCell(int x, int y, CellType type);

    /**
     * @brief Verifică dacă un punct este accesibil (nu este perete).
     * @param p Punctul de verificat.
     * @return true dacă se poate merge acolo, false altfel.
     */
    bool IsWalkable(Point p) const;

    /**
     * @brief Resetează labirintul (golește toate celulele).
     */
    void Reset();

    friend std::ostream& operator<<(std::ostream& os, const Maze& maze);
    friend std::istream& operator>>(std::istream& is, Maze& maze);
};

std::istream& operator>>(std::istream& in, Maze& maze);
std::ostream& operator<<(std::ostream& out, const Maze& maze);
