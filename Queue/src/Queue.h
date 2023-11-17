#pragma once
#include "GUI.h"

#include <iostream>
#include <vector>

namespace Queue {
	// This class is a header only queue that stores a vector of T's.
	// You can add an item to the queue, view the first item in the queue,
	// and you can pop the first item from the queue.
	// 
	// NOTE: this is a header only class, because the templates would otherwise 
	// assert when the cpp file is not included too (the definitions are then missing).
	template<typename T>
	class Queue
	{
	public:
		Queue() = default;
		~Queue() = default;

		// Add an item to the queue.
		void Enqueue(T value) {
			m_Queue.push_back(value);
		}

		// Retrieve the first item in the queue.
		T View() const {
			return *m_Queue.begin();
		}

		// Pop the first item in the queue.
		T Dequeue() {
			T queuedItem = *m_Queue.begin();
			m_Queue.erase(m_Queue.begin());
			return queuedItem;
		}

		typename std::vector<T>::iterator begin() { return m_Queue.begin(); }
		typename std::vector<T>::iterator end() { return m_Queue.end(); }

		// Print the entire contents of the queue to the console.
		friend std::ostream& operator <<(std::ostream& os, Queue<T>& queue) {
			int i = 0;
			for (auto it = queue.begin(); it != queue.end(); it++)
			{
				os << GUI::CreateHeader("Queue item " + std::to_string(i) + ": " + std::to_string(*it), 2) << std::endl;
				i++;
			}
			return os;
		}
	private:
		std::vector<T> m_Queue;
	};
}
