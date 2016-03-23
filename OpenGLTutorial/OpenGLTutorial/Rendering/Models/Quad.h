#pragma once
#include "Model.h"
#include "../../Managers/Shader_Manager.h"

namespace Rendering
{
	namespace Models
	{
		class Quad : public Models::Model
		{
		public:
			Quad(glm:: vec3 position);
			~Quad();

			void Create();
			void Draw(const float& time, unsigned int width, unsigned int height);
			virtual void Update() override final;
		};
	}
}