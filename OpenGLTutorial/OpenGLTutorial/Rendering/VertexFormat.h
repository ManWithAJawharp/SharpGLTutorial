#pragma once
#include "glm\glm.hpp"

namespace Rendering
{
	struct VertexFormat
	{
	public:
		glm::vec3 position;
		glm::vec2 uv;
		glm::vec3 normal;

		VertexFormat(const glm::vec3 &iPos, const glm::vec2 &iUv, const glm::vec3 &iNormal)
		{
			position = iPos;
			uv = iUv;
			normal = iNormal;
		}

		VertexFormat() {}
	};
}