#pragma once
#include "Colour.h"

class GUI {
public:
	static const std::string CreateHeader(const std::string& content);
	static const std::string CreateHeader(const std::string& content, int indentLevel);
	static const std::string CreateHeader(const std::string& content, const std::string& colour);
	static const std::string CreateHeader(const std::string& content, const std::string& colour, int indentLevel);
	
private:
	static const std::string CreateHeaderIndentation(int indentLevel);
};