#include "NPC/Elf.h"
#include "NPC/Orc.h"
#include "Decorators/FarmerDecorator.h"
#include "Decorators/BuilderDecorator.h"
#include "Decorators/ShamanDecorator.h"
#include "NPCFactory.h"

#include <iostream>

// This prints the npc's name and details to the screen.
void print_npc_details(NPC* npc) {
	std::cout << "NPC DETAILS" << std::endl << npc;
}

int main() {
	// Create the NPC factory.
	NPCFactory factory;

	// Create an elf with the given attributes.
	NPC* elf = factory.CreateElf(false, true, true);
	print_npc_details(elf);
	std::cout << "\n";

	// Create an Orc with the given attributes.
	NPC* orch = factory.CreateOrc(true, false, true);
	print_npc_details(orch);
	std::cout << "\n";

	// Clean up the npc's.
	delete elf;
	delete orch;

	return 0;
}