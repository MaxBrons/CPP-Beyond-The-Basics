#include "btbpch.h"
#include "GameOfLife.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const int CELL_SIZE = 10;
const int GRID_WIDTH = WIDTH / CELL_SIZE;
const int GRID_HEIGHT = HEIGHT / CELL_SIZE;

GameOfLife::GameOfLife()
{
	// Initialize both grids.
	m_Grid = std::make_unique<Grid<bool>>(GRID_WIDTH, GRID_HEIGHT);
	m_NextGrid = std::make_unique<Grid<bool>>(GRID_WIDTH, GRID_HEIGHT);

	// Set each node in the grid to true or false, based on a predicate.
	m_Grid->Set([]() { return rand() % 2 == 0; });
}

int GameOfLife::CountNeighbours(int x, int y)
{
	int count = 0;

	// Get all the alive neighbours relative to the
	// given node on the x and y position.
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			int nx = (x + i + GRID_WIDTH) % GRID_WIDTH;
			int ny = (y + j + GRID_HEIGHT) % GRID_HEIGHT;

			count += m_Grid->Get(nx, ny) ? 1 : 0;
		}
	}

	// Do not count the current node as a neighbour.
	count -= m_Grid->Get(x, y) ? 1 : 0;

	return count;
}

void GameOfLife::OnUpdate()
{
	// Go trough all the nodes in the grid and set the state of each node
	// based on Conway's Game Of Life rules:
	// 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	// 2. Any live cell with two or three live neighbours lives on to the next generation.
	// 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
	// 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	for (int x = 0; x < GRID_WIDTH; ++x)
	{
		for (int y = 0; y < GRID_HEIGHT; ++y)
		{
			int neighbors = CountNeighbours(x, y);

			if (m_Grid->Get(x, y))
			{
				m_NextGrid->Set(x, y, (neighbors == 2 || neighbors == 3));
				continue;
			}

			m_NextGrid->Set(x, y, (neighbors == 3));
		}
	}

	*m_Grid = *m_NextGrid;

	Render();
}

// Create a quad (position and size) for each living node in the grid.
void GameOfLife::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_QUADS);
	for (int x = 0; x < GRID_WIDTH; ++x)
	{
		for (int y = 0; y < GRID_HEIGHT; ++y)
		{
			if (m_Grid->Get(x, y))
			{
				float xpos = x * CELL_SIZE * 2.0f / WIDTH - 1.0f;
				float ypos = y * CELL_SIZE * 2.0f / HEIGHT - 1.0f;

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