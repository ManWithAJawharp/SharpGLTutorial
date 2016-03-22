#include "Model.h"

using namespace Rendering;
using namespace Models;

unsigned int verticesN;

Model::Model(glm::vec3 position)
{
	this->position = position;
}

Model::Model(const char* path, glm::vec3 position)
{
	std::vector<VertexFormat> vertices;

	OBJLoader::LoadOBJ(path, vertices);

	verticesN = vertices.size();

	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * verticesN, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::uv)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::normal)));
	glBindVertexArray(0);

	this->vao = vao;
	this->vbos.push_back(vbo);

	//this->texture = BMPLoader::LoadBMP("Resources\\Textures\\priestGreen.bmp");

	this->position = position;
}

Model::~Model()
{
	Destroy();
}

void Model::Update()
{
}

void Model::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const float& time)
{
	model_matrix = glm::mat4();
	/*model_matrix = glm::rotate_slow(model_matrix, 0.5f * time, glm::vec3(0, 1, 0));
	model_matrix = glm::rotate_slow(model_matrix, 1.0f * time, glm::vec3(0, 0, 1));*/
	model_matrix = glm::translate(model_matrix, position);

	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "model_matrix"), 1, false, &model_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glUniform1f(glGetUniformLocation(program, "time"), time);
	glBindVertexArray(vao);
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texture);

	glDrawArrays(GL_TRIANGLES, 0, verticesN);
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
}