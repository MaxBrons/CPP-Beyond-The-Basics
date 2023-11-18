#pragma once
#include "NPC.h"

namespace DecoratorPattern
{
	// Return the orc name when the operation is excecuted.
	class Orc : public NPC
	{
	public:
		Orc() = default;
		~Orc() = default;

		std::string Execute() const override {
			return " | Name: Orch\n";
		}
	};
}