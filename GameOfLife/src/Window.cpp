#include "btbpch.h"
#include "Window.h"

// At the moment, there can only be one window open at the same time.
bool Window::s_Initialized = false;

Window::Window(const WindowProperties& properties)
	:m_WindowProperties(properties)
{
	Init(properties);
}

Window::~Window()
{
	Shutdown();
}

// Initialize this window with the given properties.
void Window::Init(const WindowProperties& properties)
{
	if (s_Initialized)
		return;

	s_Initialized = true;

	// Set all the properies used for the GLFW window.
	m_WindowProperties.Width = properties.Width;
	m_WindowProperties.Height = properties.Height;
	m_WindowProperties.Title = properties.Title;
	m_WindowProperties.VSync = properties.VSync;

	int success = glfwInit();
	BTB_ASSERT(success, "Glfw could not be initialized");

	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

#ifdef BTB_DEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
	// Create a GLFW window and make it as the current active window.
	m_NativeWindow = glfwCreateWindow((int)properties.Width, (int)properties.Height, m_WindowProperties.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_NativeWindow);

	success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	BTB_ASSERT(success, "Glad could not be initialized");

	SetVSync(m_WindowProperties.VSync);
};

// Close the window and shutdown the GLFW library.
void Window::Shutdown()
{
	glfwDestroyWindow(m_NativeWindow);
	glfwTerminate();
}

// Swap the front and back buffer and poll the GLFW events.
void Window::OnUpdate()
{
	glfwSwapBuffers(m_NativeWindow);
	glfwPollEvents();
}

// Set VSync to the given value.
void Window::SetVSync(bool enabled)
{
	glfwSwapInterval(enabled);
	m_WindowProperties.VSync = enabled;
}