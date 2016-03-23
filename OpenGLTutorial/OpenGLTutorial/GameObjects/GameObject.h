#pragma once
#include "Transform.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace GameObjects
{
	class GameObject
	{
	public:
		GameObject();
		GameObject(glm::vec3 position);
		~GameObject();

		glm::mat4 GetTransformMatrix();

		Transform transform;
	};
}