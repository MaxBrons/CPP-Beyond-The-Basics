#include "NPCFactory.h"

#include "Decorators/FarmerDecorator.h"
#include "Decorators/BuilderDecorator.h"
#include "Decorators/ShamanDecorator.h"

// Create an elf with the given attributes.
NPC* NPCFactory::CreateElf(bool hasFarmerAttrib, bool hasBuilderAttrib, bool hasShamanAttrib)
{
	NPC* elf = new Elf();
	elf = hasFarmerAttrib ? new FarmerDecorator(elf) : elf;
	elf = hasBuilderAttrib ? new BuilderDecorator(elf) : elf;
	elf = hasShamanAttrib ? new ShamanDecorator(elf) : elf;
	
	return elf;
}

// Create an orc with the given attributes.
NPC* NPCFactory::CreateOrc(bool hasFarmerAttrib, bool hasBuilderAttrib, bool hasShamanAttrib)
{
	NPC* orc = new Orc();
	orc = hasFarmerAttrib ? new FarmerDecorator(orc) : orc;
	orc = hasBuilderAttrib ? new BuilderDecorator(orc) : orc;
	orc = hasShamanAttrib ? new ShamanDecorator(orc) : orc;

	return orc;
}

