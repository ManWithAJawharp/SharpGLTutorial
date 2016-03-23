#pragma once
#include "glm/glm.hpp"

namespace GameObjects
{
	struct Transform
	{
	public:
		Transform()
		{
			position = glm::vec3(0.0);
			rotation = glm::vec3(0.0);
			scale = glm::vec3(1.0);
		}

		Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
		{
			this->position = position;
			this->rotation = rotation;
			this->scale = scale;
		}

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}