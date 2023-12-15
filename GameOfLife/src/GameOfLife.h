#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <vector>

class GameOfLife {
public:
    GameOfLife();
    void OnUpdate();

private:
    void Render();

private:
    std::vector<std::vector<bool>> m_Grid;
    std::vector<std::vector<bool>> m_NextGrid;

    void InitializeGrid();
    int CountNeighbours(int x, int y);
};