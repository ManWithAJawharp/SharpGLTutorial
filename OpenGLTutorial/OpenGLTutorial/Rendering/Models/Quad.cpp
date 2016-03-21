#include "Quad.h"

using namespace Rendering;
using namespace Models;

glm::mat4x4* modelMatrix;

Quad::Quad(glm::vec3 position) : Model(position)
{

}

Quad::~Quad()
{

}

void Quad::Create()
{
	GLuint vao;
	GLuint vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(-0.5, 0.25, 1), glm::vec2(1, 0), glm::vec3(1, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.5, 0.75, 1), glm::vec2(1, 0), glm::vec3(1, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(0, 0.25, 0), glm::vec2(1, 0), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(0, 0.75, 0), glm::vec2(1, 0), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(0.5, 0.25, 1), glm::vec2(1, 0), glm::vec3(-1, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(0.5, 0.75, 1), glm::vec2(1, 0), glm::vec3(-1, 0, -1)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 6, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::uv)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::normal)));
	glBindVertexArray(0);

	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Quad::Update()
{

}

void Quad::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const float& time)
{
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
}