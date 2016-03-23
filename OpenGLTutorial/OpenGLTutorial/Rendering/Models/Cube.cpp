#include "Cube.h"
#include "..\..\Managers\Scene_Manager.h"

using namespace Rendering;
using namespace Models;

Cube::Cube(glm::vec3 position) : Model(position)
{
	this->position = position;

	model_matrix = glm::mat4(
		0.5, 0, 0, 0,
		0, 0.5, 0, 0,
		0, 0, 0.5, 0,
		0, 0, 0, 1);
}

Cube::~Cube()
{

}

void Cube::Create()
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	//	Front face
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec2(1, 0), glm::vec3(0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec2(0, 0), glm::vec3(0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(1, 1), glm::vec3(0, 0, 1)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec2(0, 1), glm::vec3(0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(1, 1), glm::vec3(0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec2(0, 0), glm::vec3(0, 0, 1)));

	//	Top face
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec2(1, 0), glm::vec3(0, 1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec2(0, 0), glm::vec3(0, 1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(1, 1), glm::vec3(0, 1, 0)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec2(0, 1), glm::vec3(0, 1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(1, 1), glm::vec3(0, 1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec2(0, 0), glm::vec3(0, 1, 0)));

	//	Right face
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec2(1, 0), glm::vec3(1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec2(0, 0), glm::vec3(1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(1, 1), glm::vec3(1, 0, 0)));

	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec2(0, 1), glm::vec3(1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(1, 1), glm::vec3(1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec2(0, 0), glm::vec3(1, 0, 0)));

	//	Back face
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec2(1, 0), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 1), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec2(0, 0), glm::vec3(0, 0, -1)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec2(1, 0), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec2(0, 0), glm::vec3(0, 0, -1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 1), glm::vec3(0, 0, -1)));

	//	Bottom face
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec2(1, 0), glm::vec3(0, -1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 1), glm::vec3(0, -1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec2(0, 0), glm::vec3(0, -1, 0)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec2(1, 0), glm::vec3(0, -1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec2(0, 0), glm::vec3(0, -1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 1), glm::vec3(0, -1, 0)));

	//	Left face
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec2(1, 0), glm::vec3(-1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 1), glm::vec3(-1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec2(0, 0), glm::vec3(-1, 0, 0)));

	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec2(1, 0), glm::vec3(-1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec2(0, 0), glm::vec3(-1, 0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 1), glm::vec3(-1, 0, 0)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 36, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::uv)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::normal)));
	glBindVertexArray(0);

	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Cube::Update()
{
}

void Cube::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& viewPosition, const float& time)
{
	model_matrix = glm::mat4();
	model_matrix = glm::scale(model_matrix, glm::vec3(4.0, 0.5f, 4.0));
	/*model_matrix = glm::rotate_slow(model_matrix, 0.5f * time, glm::vec3(0, 1, 0));
	model_matrix = glm::rotate_slow(model_matrix, 1.0f * time, glm::vec3(0, 0, 1));*/
	model_matrix = glm::translate(model_matrix, position);

	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "model_matrix"), 1, false, &model_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "viewPosition"), 1, false, &viewPosition[0]);
	glUniform1f(glGetUniformLocation(program, "time"), time);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}