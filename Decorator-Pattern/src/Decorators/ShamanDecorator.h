#pragma once
#include "../Decorators/NPCDecorator.h"

namespace DecoratorPattern
{
	// Add a shaman attribute tag to the given NPC.
	class ShamanDecorator : public NPCDecorator
	{
	public:
		ShamanDecorator(NPC* npc) : NPCDecorator(npc) {}
		~ShamanDecorator() = default;

		std::string Execute() const override {
			return NPCDecorator::Execute() + " | Attribute: Shaman\n";
		}
	};
}
