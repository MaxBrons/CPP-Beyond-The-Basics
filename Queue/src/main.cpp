#include "Queue.h"

void DisplayHeader(const std::string& header) {
	std::cout << GUI::CreateHeader(header, Colour::Background::Green) << std::endl;
}

void DisplaySubHeader(const std::string& header) {
	std::cout << GUI::CreateHeader(header, Colour::Background::Blue, 1) << std::endl;
}

void PrintLine(const std::string& body = "") {
	std::cout << body << std::endl;
}

int main() {
	// Output the project header to the screen.
	DisplayHeader(" QUEUE ");

	PrintLine("The queue is still empty, lets fix that.");
	PrintLine("1. Enqueuing items....");
	PrintLine("2. Printing the items to the screen...\n");

	DisplaySubHeader("VIEW ITEMS");

	// Create the queue and add a couple of items to the queue.
	Queue::Queue<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(231);
	queue.Enqueue(99);
	queue.Enqueue(3);

	// Print the queue to the console to show it is not empty.
	std::cout << queue;
	PrintLine();

	PrintLine("Lets look at the next item in the queue.");
	PrintLine("3. Peeking the queue...\n");

	// Print the first item in the queue to the console to show 
	// that you can peek into the queue.
	DisplaySubHeader("VIEW NEXT ITEM");
	PrintLine(GUI::CreateHeader("Next item: " + std::to_string(queue.View()), 2));
	PrintLine();

	PrintLine("Lets now dequeue the first item in the queue.");
	PrintLine("4. Dequeuing the first item in the queue...\n");

	// Pop the first item from the queue and print the next 
	// item in the queue.
	queue.Dequeue();

	// Print the next item in the queue to the console.
	PrintLine("And now that the queue has moved, the next item in the queue is...\n");
	DisplaySubHeader("VIEW NEXT ITEM");
	PrintLine(GUI::CreateHeader("Next item: " + std::to_string(queue.View()), 2));
	PrintLine();

	// Print the item again to the console to show that it all 
	// behaves as a queue.
	DisplaySubHeader("VIEW NEXT ITEM AGAIN");
	PrintLine(GUI::CreateHeader("Next item: " + std::to_string(queue.View()), 2));

	return 0;
}