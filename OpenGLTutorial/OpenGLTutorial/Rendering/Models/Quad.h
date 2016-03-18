#pragma once
#include "Model.h"

namespace Rendering
{
	namespace Models
	{
		class Quad : public Models::Model
		{
		public:
			Quad();
			~Quad();

			void Create();
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix, const float& time) override final;
			virtual void Update() override final;
		};
	}
}