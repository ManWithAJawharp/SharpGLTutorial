#include "Quad.h"

using namespace Rendering;
using namespace Models;

glm::mat4x4* modelMatrix;

unsigned int ibo, num_indices;

Quad::Quad(glm::vec3 position) : Model(position)
{

}

Quad::~Quad()
{

}

void Quad::Create()
{
	Managers::Shader_Manager::CreateProgram("postProcessing", "Resources\\Shaders\\ppVertex.glsl", "Resources\\Shaders\\ppFragment.glsl");
	program = Managers::Shader_Manager::GetShader("postProcessing");

	GLuint vao;
	GLuint vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//std::vector<VertexFormat> vertices;
	//vertices.push_back(VertexFormat(glm::vec3(-1, 1, 0), glm::vec2(0, 1), glm::vec3(0, 0, 1)));
	//vertices.push_back(VertexFormat(glm::vec3(-1, -1, 0), glm::vec2(0, 0), glm::vec3(0, 0, 1)));
	//vertices.push_back(VertexFormat(glm::vec3(1, -1, 0), glm::vec2(1, 0), glm::vec3(0, 0, 1)));

	//vertices.push_back(VertexFormat(glm::vec3(-1, 1, 0), glm::vec2(0, 1), glm::vec3(0, 0, 1)));
	//vertices.push_back(VertexFormat(glm::vec3(1, 1, 0), glm::vec2(1, 1), glm::vec3(0, 0, 1)));
	//vertices.push_back(VertexFormat(glm::vec3(1, -1, 0), glm::vec2(1, 0), glm::vec3(0, 0, 1)));

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(-1, -1, 0), glm::vec2(0, 0), glm::vec3(0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1, -1, 0), glm::vec2(1, 0), glm::vec3(0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1, 1, 0), glm::vec2(1, 1), glm::vec3(0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1, 1, 0), glm::vec2(0, 1), glm::vec3(0, 0, 1)));

	std::vector<unsigned int> indices;
	indices.push_back(0); indices.push_back(1); indices.push_back(2);
	indices.push_back(2); indices.push_back(3); indices.push_back(0);

	//glGenBuffers(1, &vbo);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 6, &vertices[0], GL_STATIC_DRAW);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::uv)));
	//glEnableVertexAttribArray(2);
	//glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::normal)));
	//glBindVertexArray(0);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 4, &vertices[0], GL_STATIC_DRAW);
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, &indices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::uv)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::normal)));
	num_indices = 6;


	//draw
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Quad::Update()
{

}

void Quad::Draw(const float& time, unsigned int width, unsigned int height)
{
	glUseProgram(program);

	/*glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, fbo.getColorTexture());
	glUniform1i(glGetUniformLocation(program, "texture_color"), 1);
	glActiveTexture(GL_TEXTURE0 + 2);
	glBindTexture(GL_TEXTURE_2D, fbo.getDepthTexture());
	glUniform1i(glGetUniformLocation(program, "texture_depth"), 2);

	glUniform1i(glGetUniformLocation(program, "screen_width"), width);
	glUniform1i(glGetUniformLocation(program, "screen_height"), height);

	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 6);*/

	/*glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, fbo.getColorTexture());
	glUniform1i(glGetUniformLocation(program, "texture_color"), 1);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, fbo.getDepthTexture());
	glUniform1i(glGetUniformLocation(program, "texture_depth"), 2);
	glUniform1i(glGetUniformLocation(program, "screen_width"), width);
	glUniform1i(glGetUniformLocation(program, "screen_height"), height);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);*/
}