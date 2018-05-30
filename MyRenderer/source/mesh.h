#pragma once
class Mesh
{
public:
	Mesh() : triCount(0), vao(0), vbo(0), ibo(0) {}
	~Mesh();

protected:
	unsigned int triCount;
	unsigned int vao, vbo, ibo;

};

