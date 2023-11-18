#pragma once
#include "../NPC/NPC.h"

namespace DecoratorPattern
{
	// This is a base class for all the npc decorator classes.
	// This simply chains the execute method with the given npc.
	class NPCDecorator : public NPC
	{
	public:
		NPCDecorator(NPC* npc)
			: m_NPC(npc)
		{
		}
		~NPCDecorator() = default;

		std::string Execute() const override {
			return m_NPC->Execute();
		}
	protected:
		NPC* m_NPC;
	};
}