#pragma once
#include "NPC.h"

// Return the elf name when the operation is excecuted.
class Elf : public NPC
{
public:
	Elf() = default;
	~Elf() = default;

	std::string Execute() const override {
		return "| NAME: Elf\n";
	}
};