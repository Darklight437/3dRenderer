#pragma once
#include <glm\vec4.hpp>
#include <glm\vec2.hpp>
class Mesh
{
public:
	Mesh(){};

	~Mesh();

	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord;

	};

	void initialiseQuad();
	void initialiseMesh(unsigned int vertCount, const Vertex* verts, unsigned int indexCount = 0, unsigned int* indices = nullptr);
	virtual void draw();

protected:
	unsigned int triCount = 0;
	unsigned int vertArrObj = 0, vertBuffObj = 0, indexBuffObj = 0;


};

