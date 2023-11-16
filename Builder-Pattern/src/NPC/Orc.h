#pragma once
#include "NPC.h"

// Return the orc name when the operation is excecuted.
class Orc : public NPC
{
public:
	Orc() = default;
	~Orc() = default;

	std::string Execute() const override {
		return "| NAME: Orch\n";
	}
};