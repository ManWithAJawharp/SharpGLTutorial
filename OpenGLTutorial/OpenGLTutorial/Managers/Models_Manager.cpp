#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager()
{
	Models::Cube* cube0 = new Models::Cube(glm::vec3(0, -1, 0));
	cube0->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube0->Create();
	gameModelList["cube0"] = cube0;

	Models::Model* priest = new Models::Model("Resources\\Models\\Priest.obj", "Resources\\Textures\\priestGreen.bmp", glm::vec3(-1, 0, 1));
	priest->SetProgram(Shader_Manager::GetShader("colorShader"));
	gameModelList["priest"] = priest;

	Models::Model* suzanne = new Models::Model("Resources\\Models\\Suzanne.obj", "Resources\\Textures\\priestGreen.bmp", glm::vec3(1, 1, -1));
	suzanne->SetProgram(Shader_Manager::GetShader("colorShader"));
	gameModelList["suzanne"] = suzanne;
}

Models_Manager::~Models_Manager()
{
	for (auto model : gameModelList)
	{
		delete model.second;
	}

	gameModelList.clear();
}

void Models_Manager::DeleteModel(const std::string& gameModelName)
{
	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

void Models_Manager::Update()
{
	for (auto model : gameModelList)
	{
		model.second->Update();
	}
}

void Models_Manager::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& viewPosition, const float& time)
{
	for (auto model : gameModelList)
	{
		model.second->Draw(projection_matrix, view_matrix, viewPosition, time);
	}
}