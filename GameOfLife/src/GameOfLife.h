#pragma once
#include "Core.h"
#include "Grid.h"

class GameOfLife {
public:
    GameOfLife();
    void OnUpdate();

private:
    void Render();
    int CountNeighbours(int x, int y);

private:
    std::unique_ptr<Grid<bool>> m_Grid;
    std::unique_ptr<Grid<bool>> m_NextGrid;
};