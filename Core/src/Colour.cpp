#include "btbpch.h"
#include "Colour.h"

const std::string Colour::Default = "\033[0m";

const std::string Colour::Foreground::Black = "\033[30m";
const std::string Colour::Foreground::White = "\033[37m";
const std::string Colour::Foreground::Red = "\033[31m";
const std::string Colour::Foreground::Green = "\033[32m";
const std::string Colour::Foreground::Blue = "\033[34m";
const std::string Colour::Foreground::Yellow = "\033[33m";
const std::string Colour::Foreground::Cyan = "\033[36m";
const std::string Colour::Foreground::Purple = "\033[35m";

const std::string Colour::Background::Black = "\033[40m";
const std::string Colour::Background::White = "\033[47m";
const std::string Colour::Background::Red = "\033[41m";
const std::string Colour::Background::Green = "\033[42m";
const std::string Colour::Background::Blue = "\033[44m";
const std::string Colour::Background::Yellow = "\033[43m";
const std::string Colour::Background::Cyan = "\033[46m";
const std::string Colour::Background::Purple = "\033[45m";

// Colour a string with a given colour.
const std::string Colour::ClrStr(const std::string& in, const std::string& colour)
{
	return colour + in + Colour::Default;
}
