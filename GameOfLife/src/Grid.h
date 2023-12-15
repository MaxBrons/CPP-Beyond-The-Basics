#pragma once
#include "btbpch.h"

template<typename T>
class Grid
{
public:
	Grid(uint32_t width, uint32_t height)
		:m_Width(width), m_Height(height)
	{
		m_Grid.resize(m_Width, std::vector<T>(m_Height, false));
	}
	virtual ~Grid() = default;

	// Return the value of the node in the grid at the given xy position.
	const T& Get(int x, int y) const { return m_Grid[x][y]; }

	// Set the value of the node in the grid at the given xy position.
	void Set(int x, int y, const T& value)
	{
		m_Grid[x][y] = value;
	}

	// Set the value of each node in the grid based on a predicate function.
	template<typename Fn>
	void Set(Fn func)
	{
		for (int y = 0; y < m_Grid.size(); y++)
		{
			for (int x = 0; x < m_Grid[y].size(); x++)
			{
				m_Grid[x][y] = func();
			}
		}
	}

	// Array accessor overrides to access the grid vector easier.
	std::vector<T>& operator [](std::size_t index) { return m_Grid[index]; }
	const std::vector<T>& operator [](std::size_t index) const { return m_Grid[index]; }

	// Assignment operator overload to copy the data from one grid to the other.
	Grid& operator=(const Grid& other)
	{
		m_Width = other.m_Width;
		m_Height = other.m_Height;
		m_Grid = other.m_Grid;
		
		return *this;
	}
private:
	std::vector<std::vector<T>> m_Grid;
	uint32_t m_Width, m_Height;
};
