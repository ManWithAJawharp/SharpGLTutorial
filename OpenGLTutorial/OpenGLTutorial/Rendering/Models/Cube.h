#pragma once
#include "Model.h"

namespace Rendering
{
	namespace Models
	{
		class Cube : public Model
		{
		public:
			Cube(glm::vec3 position);
			~Cube();

			void Create();
			virtual void Update() override final;
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const glm::vec3& viewPosition, const unsigned int& lightmapTexture, const glm::mat4& lightMatrix, const float& time) override final;
		};
	}
}