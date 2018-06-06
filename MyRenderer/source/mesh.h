#pragma once
#include <glm\vec4.hpp>
#include <glm\vec2.hpp>
class Mesh
{
public:
	Mesh(){};

	~Mesh();

	enum primitiveMesh
	{
		BOX, CYLINDER, PYRAMID
	};

	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord;

	};

	void initialiseQuad();
	void initialisePrimitive(primitiveMesh type);
	void initialiseMesh(unsigned int vertCount, const Vertex* verts, unsigned int indexCount, unsigned int* indices);
	virtual void draw();

protected:
	unsigned int triCount = 0;
	unsigned int vertArrObj = 0, vertBuffObj = 0, indexBuffObj = 0;


};

