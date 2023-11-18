#pragma once
#include "../Decorators/NPCDecorator.h"

namespace DecoratorPattern
{
	// Add a builder attribute tag to the given NPC.
	class BuilderDecorator : public NPCDecorator
	{
	public:
		BuilderDecorator(NPC* npc) : NPCDecorator(npc) {}
		~BuilderDecorator() = default;

		std::string Execute() const override {
			return NPCDecorator::Execute() + " | Attribute: Builder\n";
		}
	};
}