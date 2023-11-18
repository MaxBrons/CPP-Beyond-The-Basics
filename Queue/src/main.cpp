#include "Queue.h"

// Easy method for printing a gui header to the console.
inline void DisplayHeader(const std::string& header) {
	std::cout << GUI::CreateHeader(header, Colour::Background::Green) << std::endl;
}

// Easy method for printing a gui sub header to the console.
inline void DisplaySubHeader(const std::string& header) {
	std::cout << GUI::CreateHeader(header, Colour::Background::Blue, 1) << std::endl;
}

// Easy method for printing to the console.
inline void PrintLine(const std::string& body = "") {
	std::cout << body << std::endl;
}

// Display the basics of the queue, like adding, removing and viewing.
void DisplayQueueExample()
{
	// Output the project step header to the screen.
	DisplayHeader(" QUEUE ");
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
	std::cout << queue << std::endl << GUI::CreateHeader("Queue size: " + std::to_string(queue.Size()), 2) << std::endl;
	PrintLine();

	PrintLine("3. Viewing the queue...\n");

	// Print the first item in the queue to the console to show 
	// that you can peek into the queue.
	DisplaySubHeader("VIEW NEXT ITEM");
	PrintLine(GUI::CreateHeader("Next item: " + std::to_string(queue.View()), 2));
	PrintLine();

	PrintLine("4. Dequeuing the first item in the queue...");

	// Pop the first item from the queue and print the next 
	// item in the queue.
	queue.Dequeue();

	// Print the next item in the queue to the console.
	PrintLine("5. Viewing the queue...\n");

	DisplaySubHeader("VIEW NEXT ITEM");
	PrintLine(GUI::CreateHeader("Next item: " + std::to_string(queue.View()), 2));
	PrintLine();

	// Print the queue again to the console to show the end result.
	DisplaySubHeader("FINAL QUEUE");
	std::cout << queue << std::endl << GUI::CreateHeader("Queue size: " + std::to_string(queue.Size()), 2) << std::endl;
	PrintLine();
}

// Display a that the queue (float type) can be sorted.
void DisplayFloatQueueExample()
{
	// Output the project step header to the screen.
	DisplayHeader(" FLOAT QUEUE SORTING ");
	PrintLine("1. Enqueuing items....");
	PrintLine("2. Printing the items to the screen...\n");

	DisplaySubHeader("VIEW ITEMS");

	// Create the queue and add a couple of items to the queue.
	Queue::Queue<float> queue;
	queue.Enqueue(10.0f);
	queue.Enqueue(231.0f);
	queue.Enqueue(99.0f);
	queue.Enqueue(3.0f);

	// Print the queue to the console to show its contents.
	std::cout << queue << std::endl;

	PrintLine("3. Sorting the queue...\n");

	// Sort the queue to show the queue from lowest to highest value.
	queue.Sort();

	DisplaySubHeader("SORT QUEUE");

	// Print the queue to the console to show its contents again.
	std::cout << queue << std::endl;
	PrintLine();
}

// Display a that the queue (std::string type) can be sorted.
void DisplayStringQueueExample()
{
	// Output the project step header to the screen.
	DisplayHeader(" STRING QUEUE SORTING ");
	PrintLine("1. Enqueuing items....");
	PrintLine("2. Printing the items to the screen...\n");

	DisplaySubHeader("VIEW ITEMS");

	// Create the queue and add a couple of items to the queue.
	Queue::Queue<std::string> queue;
	queue.Enqueue("John");
	queue.Enqueue("Abel");
	queue.Enqueue("Baker");
	queue.Enqueue("Peter");

	// Print the queue to the console to show its contents.
	std::cout << queue << std::endl;

	PrintLine("3. Sorting the queue...\n");

	// Sort the queue to show the queue from lowest to highest value.
	queue.Sort();
	DisplaySubHeader("SORT QUEUE");

	// Print the queue to the console to show its contents again.
	std::cout << queue << std::endl;
}

int main() {
	DisplayQueueExample();
	DisplayFloatQueueExample();
	DisplayStringQueueExample();
	return 0;
}

