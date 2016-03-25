#pragma once
#include "../IGameObject.h"
#include "OBJLoader.h"
#include "../BMPLoader.h"
#include "glm\glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace Rendering
{
	namespace Models
	{
		class Model : public IGameObject
		{
		public:
			Model(glm::vec3 position);
			Model(const char* modelPath, const char* texturePath, glm::vec3 position);
			virtual ~Model();

			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& viewPosition, const unsigned int& lightmapTexture, const glm::mat4& lightMatrix, const float& time) override;
			virtual void Update() override;
			virtual void SetProgram(GLuint shaderName) override;
			virtual void Destroy() override;

			virtual GLuint GetVao() const override;
			virtual const std::vector<GLuint>& GetVbos() const override;

		protected:
			GLuint vao;
			GLuint program;
			std::vector<GLuint> vbos;

			unsigned int num_vertices;

			GLuint texture;

			glm::vec3 position;
			glm::mat4 model_matrix;
		};
	}
}