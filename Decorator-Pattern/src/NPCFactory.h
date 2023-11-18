#pragma once
#include "NPC/Orc.h"
#include "NPC/Elf.h"

namespace DecoratorPattern
{
	class NPCFactory
	{
	public:
		NPCFactory() = default;
		~NPCFactory() = default;

		static NPC* CreateElf(bool hasFarmerAttrib = false, bool hasBuilderAttrib = false, bool hasShamanAttrib = false);
		static NPC* CreateOrc(bool hasFarmerAttrib = false, bool hasBuilderAttrib = false, bool hasShamanAttrib = false);
	};
}