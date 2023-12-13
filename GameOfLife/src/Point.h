#pragma once
#include "Core.h"

#include <glad/glad.h>
#include <glm/glm.hpp>


struct Transform
{
public:
	glm::vec2 Position;
	float Rotation;
	glm::vec2 Size;

	Transform(const glm::vec2& Position, float Rotation, const glm::vec2& Size)
		: Position(Position), Rotation(Rotation), Size(Size)
	{
	}
};

class Point
{
public:
	Point(const Transform& transform);
	virtual ~Point();

private:
	Transform m_Transform;
};