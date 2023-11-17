#include "NPC/Elf.h"
#include "NPC/Orc.h"
#include "NPCFactory.h"
#include "GUI.h"

#include <iostream>

using namespace BuilderPattern;

// This prints the npc's name and details to the screen.
void print_npc_details(NPC* npc) {
	std::cout << GUI::CreateHeader("| NPC DETAILS", Colour::Background::Blue) << std::endl << npc;
}

int main() {
	// Create the NPC factory.
	NPCFactory factory;

	// Generate the top header for the project.
	std::cout << GUI::CreateHeader("DECORATED NPC'S", Colour::Background::Green) << std::endl;

	// Create an elf with the given attributes.
	NPC* elf = factory.CreateElf(false, true, true);
	print_npc_details(elf);
	std::cout << "\n";

	// Create an Orc with the given attributes.
	NPC* orch = factory.CreateOrc(true, true, true);
	print_npc_details(orch);
	std::cout << "\n";

	// Clean up the npc's.
	delete elf;
	delete orch;

	return 0;
}