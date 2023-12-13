#include "btbpch.h"
#include "Window.h"

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

void Window::Init(const WindowProperties& properties)
{
	if (s_Initialized)
		return;

	s_Initialized = true;

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
	m_NativeWindow = glfwCreateWindow((int)properties.Width, (int)properties.Height, m_WindowProperties.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_NativeWindow);

	success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	BTB_ASSERT(success, "Glad could not be initialized");

	SetVSync(m_WindowProperties.VSync);
};

void Window::Shutdown()
{
	glfwDestroyWindow(m_NativeWindow);
	glfwTerminate();
}

void Window::OnUpdate()
{
	glfwSwapBuffers(m_NativeWindow);
	glfwPollEvents();
}
void Window::SetVSync(bool enabled)
{
	glfwSwapInterval(enabled);
	m_WindowProperties.VSync = enabled;
}