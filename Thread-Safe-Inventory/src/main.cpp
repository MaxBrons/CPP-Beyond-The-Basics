#include "btbpch.h"
#include "Core.h"
#include "Inventory.h"

#include <thread>
#include <format>
#include <xstring>

const int INVENTORY_ITEMS_COUNT = 50;

Inventory<std::string> m_Inventory;

// Easy method for printing a gui header to the console.
inline void DisplayHeader(const std::string& header)
{
	std::cout << GUI::CreateHeader(header, Colour::Background::Green) << std::endl;
}

// Easy method for printing a gui sub header to the console.
inline void DisplaySubHeader(const std::string& header)
{
	std::cout << GUI::CreateHeader(header, Colour::Background::Blue, 1) << std::endl;
}

// Easy method for printing to the console.
inline void PrintLine(const std::string& body = "")
{
	std::cout << body << std::endl;
}

// A method for adding an amount of (string) items to the inventory.
void AddItems(std::string prefix)
{
	for (int i = 0; i < INVENTORY_ITEMS_COUNT; i++)
	{
		m_Inventory.Put(prefix + " | Item " + std::to_string(i));
		std::cout << (GUI::CreateHeader(GUI::CreateHeader(prefix, prefix[prefix.size()-1] == '1' ? Colour::Background::Black + Colour::Foreground::White : Colour::Background::White + Colour::Foreground::Black) + " | Item " + std::to_string(i), 2) + "\n");
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
};

// A method for removing all (string) items from the inventory.
void RemoveItems(std::string prefix)
{
	while(m_Inventory.Size() > 0)
	{
		std::cout << (GUI::CreateHeader(GUI::CreateHeader(prefix, prefix[prefix.size() - 1] == '1' ? Colour::Background::Black + Colour::Foreground::White : Colour::Background::White + Colour::Foreground::Black) + m_Inventory.Get().substr(prefix.size()), 2) + "\n");
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
};

int main()
{
	// Display the general information about the program.
	DisplayHeader(" THREAD SAFE INVENTORY ");
	
	PrintLine("1. Adding items to the inventory...");
	PrintLine();

	DisplaySubHeader("ADDING ITEMS");

	// Create two threads to add items concurrently.
	std::thread thread1(AddItems, "Thread 1");
	std::thread thread2(AddItems, "Thread 2");

	thread1.join();
	thread2.join();

	// Display the total items that are added;
	PrintLine();
	PrintLine(GUI::CreateHeader("Total items added: " + std::to_string(m_Inventory.Size()), 2));
	PrintLine();

	PrintLine("2. Removing all the items from the inventory...\n");

	DisplaySubHeader("REMOVING ITEMS");

	// Create two threads to add items concurrently.
	thread1 = std::thread(RemoveItems, "Thread 1");
	thread2 = std::thread(RemoveItems, "Thread 2");

	thread1.join();
	thread2.join();

	PrintLine();
	DisplaySubHeader("RESULTS");
	PrintLine(GUI::CreateHeader("Total items that should have been added/removed: " + std::to_string(INVENTORY_ITEMS_COUNT * 2), 2));
	PrintLine(GUI::CreateHeader("Total items removed: " + std::to_string(INVENTORY_ITEMS_COUNT * 2 - m_Inventory.Size()), 2));
	PrintLine(GUI::CreateHeader("Inventory net: " + std::to_string(m_Inventory.Size()), 2));

	return 0;
}