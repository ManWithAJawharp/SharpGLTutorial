#pragma once
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Triangle.h"
#include "../Rendering/Models/Quad.h"
#include "../Rendering/Models/Cube.h"
#include "Shader_Manager.h"
#include <map>

using namespace Rendering;

namespace Managers
{
	class Models_Manager
	{
	public:
		Models_Manager();
		~Models_Manager();

		void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const float& time);
		void Update();
		void DeleteModel(const std::string& gameModelName);
		const IGameObject& GetModel(const std::string& gameModelName);

	private:
		std::map<std::string, IGameObject*> gameModelList;
	};
}