#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifdef BTB_DEBUG
#define BTB_ASSERT(check, msg) { if(!(check)) {std::cout << msg << std::endl; __debugbreak(); } }
#else
#define BTB_ASSERT(check, msg)
#endif



