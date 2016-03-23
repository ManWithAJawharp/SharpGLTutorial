#pragma once
#include "Model.h"
#include "../../Managers/Shader_Manager.h"
#include "../Framebuffer.h"

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
			void Draw(const unsigned int& color, const unsigned int& depth, const float& time, const glm::mat4& i_pv_matrix, unsigned int width, unsigned int height);
			virtual void Update() override final;
		};
	}
}