#include "Mesh.h"
#include <glad\glad.h>


Mesh::Mesh()
{
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertArrObj);
	glDeleteBuffers(1, &vertBuffObj);
	glDeleteBuffers(1, &indexBuffObj);

}

void Mesh::initialiseQuad()
{
	//check that the mesh isnt already initialised
	assert(vertArrObj == 0);

	

	//generate buffers
	glGenBuffers(1, &vertBuffObj);
	glGenVertexArrays(1, &vertArrObj);

	//bind vertex array to a mesh wrapper
	glBindVertexArray(vertArrObj);

	//bind vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertBuffObj);


	//defining the two tris to make the maaagic quaaad
	Vertex vertices[6];
	vertices[0].position = { -0.5f, 0, 0.5f, 1 };
	vertices[1].position = { 0.5f, 0, 0.5f, 1 };
	vertices[2].position = { -0.5f, 0, -0.5f, 1 };

	vertices[3].position = { -0.5f, 0, -0.5f, 1 };
	vertices[4].position = { 0.5f, 0, 0.5f, 1 };
	vertices[5].position = { 0.5f, 0, -0.5f, 1 };

	//fill the vert buffer with these vertices
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), vertices, GL_STATIC_DRAW);




}

void Mesh::draw()
{
}
