#pragma once
#include "Core.h"

struct WindowProperties
{
	std::string Title;
	uint32_t Width;
	uint32_t Height;
	bool VSync;

	WindowProperties(const std::string& title = "Game Of Life",
		uint32_t width = 1600,
		uint32_t height = 900)
		: Title(title), Width(width), Height(height), VSync(false)
	{
	}
};

class Window
{
public:
	Window(const WindowProperties& properties);
	~Window();

	void OnUpdate();

	uint32_t GetWidth() const { return m_WindowProperties.Width; }
	uint32_t GetHeight() const { return m_WindowProperties.Height; }

	bool IsOpen() const { return !glfwWindowShouldClose(m_NativeWindow); }

	void SetVSync(bool enabled);
	bool IsVSync() const { return m_WindowProperties.VSync; }

	void* GetNativeWindow() const { return m_NativeWindow; }

	static std::unique_ptr<Window> Create(const WindowProperties& properties = WindowProperties())
	{
		return std::make_unique<Window>(properties);
	}

private:
	void Init(const WindowProperties& properties);
	void Shutdown();
private:
	static bool s_Initialized;
private:
	GLFWwindow* m_NativeWindow;
	WindowProperties m_WindowProperties;
};