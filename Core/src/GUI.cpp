#include "GUI.h"

// This creates a textblock that is used as a header.
const std::string GUI::CreateHeader(const std::string& content)
{
	return content;
}

// This creates a textblock with indentation level that is used as a header.
const std::string GUI::CreateHeader(const std::string& content, int indentLevel)
{
	return CreateHeader(content, Colour::Default, indentLevel);
}

// This creates a coloured textblock that is used as a header.
const std::string GUI::CreateHeader(const std::string& content, const std::string& colour)
{
	return colour + content + Colour::Default;
}

// This creates a coloured textblock with indentation level that is used as a header.
const std::string GUI::CreateHeader(const std::string& content, const std::string& colour, int indentLevel)
{
	if (indentLevel > 0) {
		std::string indent = CreateHeaderIndentation(indentLevel);
		return colour + indent + content + Colour::Default;
	}
	return colour + content + Colour::Default;
}

// Return a string with trailing spaces (indentation level - 1) plus the '|' sign.
const std::string GUI::CreateHeaderIndentation(int indentLevel)
{
	std::string indent;

	for (size_t i = 1; i < indentLevel; i++)
		indent += " ";

	indent += "| ";
	return indent;
}


