#include "Model.h"
#include "../../Dependencies/soil/SOIL.h"

using namespace Rendering;
using namespace Models;

Model::Model(glm::vec3 position)
{
	this->position = position;
}

Model::Model(const char* modelPath, const char* texturePath, glm::vec3 position)
{
	std::vector<VertexFormat> vertices;

	OBJLoader::LoadOBJ(modelPath, vertices);

	this->texture = TextureLoader::LoadTexture(texturePath, 256, 256);

	num_vertices = vertices.size();

	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * num_vertices, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::uv)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::normal)));

	glBindVertexArray(0);

	this->vao = vao;
	this->vbos.push_back(vbo);

	this->position = position;
}

Model::~Model()
{
	Destroy();
}

void Model::Update()
{
}

void Model::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& viewPosition, const float& time)
{
	model_matrix = glm::mat4();
	model_matrix = glm::translate(model_matrix, position);

	glUseProgram(program);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(program, "textureSampler"), 0);

	glUniformMatrix4fv(glGetUniformLocation(program, "model_matrix"), 1, false, &model_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniform3fv(glGetUniformLocation(program, "viewPosition"), 1, &viewPosition[0]);
	glUniform1f(glGetUniformLocation(program, "time"), time);
	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, num_vertices);
}

void Model::SetProgram(GLuint program)
{
	this->program = program;
}

GLuint Model::GetVao() const
{
	return vao;
}

const std::vector<GLuint>& Model::GetVbos() const
{
	return vbos;
}

void Model::Destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();

	glDeleteProgram(program);
}