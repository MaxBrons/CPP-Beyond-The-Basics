#include "GameOfLife.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const int CELL_SIZE = 10;
const int GRID_WIDTH = WIDTH / CELL_SIZE;
const int GRID_HEIGHT = HEIGHT / CELL_SIZE;

GameOfLife::GameOfLife() {
    m_Grid.resize(GRID_WIDTH, std::vector<bool>(GRID_HEIGHT, false));
    m_NextGrid.resize(GRID_WIDTH, std::vector<bool>(GRID_HEIGHT, false));
    InitializeGrid();
}

void GameOfLife::InitializeGrid() {
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            m_Grid[x][y] = rand() % 2 == 0;
        }
    }
}

int GameOfLife::CountNeighbours(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = (x + i + GRID_WIDTH) % GRID_WIDTH;
            int ny = (y + j + GRID_HEIGHT) % GRID_HEIGHT;
            count += m_Grid[nx][ny] ? 1 : 0;
        }
    }
    count -= m_Grid[x][y] ? 1 : 0;
    return count;
}

void GameOfLife::OnUpdate() {
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            int neighbors = CountNeighbours(x, y);
            if (m_Grid[x][y]) {
                m_NextGrid[x][y] = (neighbors == 2 || neighbors == 3);
            }
            else {
                m_NextGrid[x][y] = (neighbors == 3);
            }
        }
    }
    m_Grid = m_NextGrid;

    Render();
}

void GameOfLife::Render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            if (m_Grid[x][y]) {
                float xpos = x * static_cast<float>(CELL_SIZE) * 2.0f / WIDTH - 1.0f;
                float ypos = y * static_cast<float>(CELL_SIZE) * 2.0f / HEIGHT - 1.0f;

                glColor3f(1.0f, 1.0f, 1.0f);
                glVertex2f(xpos, ypos);
                glVertex2f(xpos + CELL_SIZE * 2.0f / WIDTH, ypos);
                glVertex2f(xpos + CELL_SIZE * 2.0f / WIDTH, ypos + CELL_SIZE * 2.0f / HEIGHT);
                glVertex2f(xpos, ypos + CELL_SIZE * 2.0f / HEIGHT);
            }
        }
    }
    glEnd();
}