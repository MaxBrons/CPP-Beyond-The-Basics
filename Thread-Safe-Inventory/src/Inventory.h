#pragma once
#include <mutex>

template<typename T>
class Inventory
{
public:
	Inventory() = default;
	virtual ~Inventory() = default;

	// Push back an item in the list.
	void Put(T item)
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		m_Items.push_back(item);
	}

	// Pop the first item from the list.
	T Get()
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		if (!m_Items.empty())
		{
			T item = m_Items.back();
			m_Items.pop_back();
			return item;
		}
		return T();
	}

	// Return the length of the items vector.
	auto Size() const { return m_Items.size(); }

private:
	std::vector<T> m_Items;
	std::mutex m_Mutex;
};