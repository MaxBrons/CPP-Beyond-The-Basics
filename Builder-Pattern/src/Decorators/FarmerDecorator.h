#pragma once
#include "../Decorators/NPCDecorator.h"

namespace BuilderPattern
{
	// Add a farmer attribute tag to the given NPC.
	class FarmerDecorator : public NPCDecorator
	{
	public:
		FarmerDecorator(NPC* npc) : NPCDecorator(npc) {}
		~FarmerDecorator() = default;

		std::string Execute() const override {
			return NPCDecorator::Execute() + " | Attribute: Farmer\n";
		}
	};
}