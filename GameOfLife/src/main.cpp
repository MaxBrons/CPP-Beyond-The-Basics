#include "Core.h"
#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

static int s_Width = 720;
static int s_Height = 720;

int main()
{
	auto window = Window::Create(WindowProperties("Game of life", s_Width, s_Height));

	unsigned char* data = new unsigned char[s_Width * s_Height * 3];

	for (int i = 0; i < s_Width * s_Height; i++)
	{
		auto colour = rand() % 100 > 90 ? 0xff : 0x00;
		data[i * 3] = colour;
		data[i * 3 + 1] = colour;
		data[i * 3 + 2] = colour;
	}

	while (window->IsOpen())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glDrawPixels(s_Width, s_Height, GL_RGB, GL_UNSIGNED_BYTE, data);

		window->OnUpdate();
	}

	delete[] data;
	return 0;
}