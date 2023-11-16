#include "GUI.h"

// This is used to create a coloured textblock to be used as a header.
const std::string GUI::CreateHeader(const std::string& content, const std::string colour)
{
	return colour + content + Colour::Default;
}
