#pragma once
#include <glm\vec4.hpp>
#include <glm\vec2.hpp>
class Mesh
{
public:
	Mesh() : triCount(0), vao(0), vbo(0), ibo(0) {}

	~Mesh();

	struct vertex
	{
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord

	};


protected:
	unsigned int triCount;
	unsigned int vao, vbo, ibo;


};

