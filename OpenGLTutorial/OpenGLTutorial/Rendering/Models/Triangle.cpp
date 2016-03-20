#include "Triangle.h"
#include "..\..\Managers\Scene_Manager.h"

using namespace Rendering;
using namespace Models;

float t;

Triangle::Triangle()
{
	model_matrix = glm::mat4(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);

	t = 0.0;
}

Triangle::~Triangle()
{

}

void Triangle::Create()
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(0.25, -0.5, 0.0), glm::vec4(1, 0, 0, 1), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, -0.5, 0.0), glm::vec4(0, 1, 0, 1), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(0, 0, 0.0), glm::vec4(0, 0, 1, 1), glm::vec3(0, 0, -1)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 3, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*) 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*) (offsetof(VertexFormat, VertexFormat::color)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, sizeof(VertexFormat), (void*) (offsetof(VertexFormat, VertexFormat::normal)));
	glBindVertexArray(0);

	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Triangle::Update()
{
}

void Triangle::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const float& time)
{
	model_matrix[3][1] = 0.5 * glm::sin(time);
	model_matrix[3][0] = 0.5 * glm::cos(time);

	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "model_matrix"), 1, false, &model_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniform1f(glGetUniformLocation(program, "time"), time);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}