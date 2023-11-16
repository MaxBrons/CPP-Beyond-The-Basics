#pragma once
#include <string>

static class Colour {
public:
	static class Foreground {
	public:
		static const std::string Black;
		static const std::string White;
		static const std::string Red;
		static const std::string Green;
		static const std::string Blue;
		static const std::string Yellow;
		static const std::string Cyan;
		static const std::string Purple;
	};
	static class Background {
	public:
		static const std::string Black;
		static const std::string White;
		static const std::string Red;
		static const std::string Green;
		static const std::string Blue;
		static const std::string Yellow;
		static const std::string Cyan;
		static const std::string Purple;
	};

public:
	static const std::string ClrStr(const std::string& in, const std::string& colour);
public:
	static const std::string Default;
};
