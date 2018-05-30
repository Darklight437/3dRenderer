#pragma once
#include <glm\vec4.hpp>
#include <glm\vec2.hpp>
class Mesh
{
public:
	Mesh() : triCount(0), vertArrObj(0), vertBuffObj(0), indexBuffObj(0) {}

	~Mesh();

	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord;

	};

	void initialiseQuad();

	virtual void draw();

protected:
	unsigned int triCount;
	unsigned int vertArrObj, vertBuffObj, indexBuffObj;


};

