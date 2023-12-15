#include "btbpch.h"
#include "Core.h"
#include "Window.h"
#include "GameOfLife.h"

#include <chrono>
#include <thread>

const int WIDTH = 800;
const int HEIGHT = 800;

int main() {
    auto window = Window::Create({ "Conway's Game of Life", WIDTH, HEIGHT });

    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);

    GameOfLife game;

    while (window->IsOpen()) {
        game.OnUpdate();

        // Introduce a delay (adjust the milliseconds based on your preference)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        window->OnUpdate();
    }
    return 0;
}
