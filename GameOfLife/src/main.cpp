#include "btbpch.h"
#include "Core.h"
#include "Window.h"
#include "GameOfLife.h"

#include <chrono>
#include <thread>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

int main() {
    // Create an GLFW window with a name, width and height.
    auto window = Window::Create({ "Conway's Game of Life", WINDOW_WIDTH, WINDOW_HEIGHT });

    {
        GameOfLife game;

        // Update the state of the Game Of Life and render 
        // the new result to the screen after a set delay.
        while (window->IsOpen())
        {
            game.OnUpdate();

            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            window->OnUpdate();
        }
    }
    return 0;
}
