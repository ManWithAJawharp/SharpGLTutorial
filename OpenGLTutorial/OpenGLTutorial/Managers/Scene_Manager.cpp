#include "Scene_Manager.h"
using namespace Managers;

Scene_Manager::Scene_Manager()
{
	glEnable(GL_DEPTH_TEST);

	shader_manager = new Shader_Manager();
	shader_manager->CreateProgram("colorShader", "Shaders\\Vertex_Shader.glsl", "Shaders\\Fragment_Shader.glsl");

	view_matrix = glm::lookAt(glm::vec3(0, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	models_manager = new Models_Manager();

	time = 0.0;
}

Scene_Manager::~Scene_Manager()
{
	delete shader_manager;
	delete models_manager;
}

void Scene_Manager::notifyBeginFrame()
{
	

	time += 1.0 / 60;

	view_matrix = glm::lookAt(glm::vec3(3 * glm::cos(time), 1.5 * sin(0.5 * time) + 2, 3 * glm::sin(time)), glm::vec3(0, 0.5, 0), glm::vec3(0, 1, 0));

	models_manager->Update();
}

void Scene_Manager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1, 0.3, 0.1, 1);

	models_manager->Draw(projection_matrix, view_matrix, time);
}

void Scene_Manager::notifyEndFrame()
{

}

void Scene_Manager::notifyReshape(int width, int height, int prev_width, int prev_height)
{
	float ar = (float)glutGet(GLUT_WINDOW_WIDTH) /
		(float)glutGet(GLUT_WINDOW_HEIGHT);
	float angle = 45.0f, near1 = 0.1f, far1 = 2000.0f;

	projection_matrix[0][0] = 1.0f / (ar * tan(angle / 2.0f));
	projection_matrix[1][1] = 1.0f / tan(angle / 2.0f);
	projection_matrix[2][2] = (-near1 - far1) / (near1 - far1);
	projection_matrix[2][3] = 1.0f;
	projection_matrix[3][2] = 2.0f * near1 * far1 / (near1 - far1);

	projection_matrix = glm::perspective(45.0f, 1.5f, 0.1f, 2000.0f);
}