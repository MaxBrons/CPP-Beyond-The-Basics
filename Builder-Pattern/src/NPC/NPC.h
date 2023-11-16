#pragma once

#include <iostream>

// This is the base class for all the npc's.
// This simply prints the name and attributes 
// of the npc to the screen.
class NPC
{
public:
	NPC() = default;
	virtual ~NPC() = default;

	virtual std::string Execute() const = 0;

	friend std::ostream& operator <<(std::ostream& os, NPC* npc) {
		os << npc->Execute();
		return os;
	}
};

