#pragma once
#include "glm\glm.hpp"

namespace Rendering
{
	struct VertexFormat
	{
		glm::vec3 position;
		glm::vec4 color;
		glm::vec3 normal;

		VertexFormat(const glm::vec3 &iPos, const glm::vec4 &iColor, const glm::vec3 &iNormal)
		{
			position = iPos;
			color = iColor;
			normal = iNormal;
		}

		VertexFormat() {}
	};
}