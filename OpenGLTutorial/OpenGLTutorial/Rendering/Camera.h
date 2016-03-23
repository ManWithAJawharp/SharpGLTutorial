#pragma once
#include "glm/glm.hpp"

namespace Rendering
{
	class Camera
	{
	public:
		Camera(glm::vec3 position);
		Camera(const glm::mat4& view_matrix);
		~Camera();

		glm::mat4 GetViewMatrix();

	private:
		glm::mat4 view_matrix;
	};
}