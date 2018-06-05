#include "Mesh.h"
#include <glad\glad.h>





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

	vertices[0].normal = { 1.0f, 0, 0.0f, 1 };
	vertices[1].normal = { 0.0f, 1.0, 0.0f, 1 };
	vertices[2].normal = { 0.0f, 0, 1.0f, 1 };

	vertices[3].normal = { 0.5f, 0, 0.5f, 1 };
	vertices[4].normal = { 1.0f, 0, 0.5f, 1 };
	vertices[5].normal = { 0.5f, 0, 0.5f, 1 };

	//fill the vert buffer with these vertices
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex),(void*)offsetof(Vertex, normal));

	//unbind current buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//quad has 2 tris so
	triCount = 2;


}

void Mesh::draw()
{
	glBindVertexArray(vertArrObj);
	//figure out if using vertices or indices
	if (indexBuffObj != 0)
	{
		glDrawElements(GL_TRIANGLES, 3 * triCount, GL_UNSIGNED_INT, 0);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, 3 * triCount);
	}

}
