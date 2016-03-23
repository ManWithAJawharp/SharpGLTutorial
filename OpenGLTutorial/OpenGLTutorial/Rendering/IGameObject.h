#pragma once
#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"
#include "VertexFormat.h"
#include <iostream>
#include <vector>

namespace Rendering
{
	class IGameObject
	{
	public:
		virtual ~IGameObject() = 0;

		virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& viewPosition, const float& time) = 0;
		virtual void Update() = 0;
		virtual void SetProgram(GLuint shaderName) = 0;
		virtual void Destroy() = 0;

		virtual GLuint GetVao() const = 0;
		virtual const std::vector<GLuint>& GetVbos() const = 0;
	};

	inline IGameObject::~IGameObject()
	{

	}
}