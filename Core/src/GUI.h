#pragma once
#include "Colour.h"

static class GUI {
public:
	static const std::string CreateHeader(const std::string& content, const std::string colour = Colour::Default);
};