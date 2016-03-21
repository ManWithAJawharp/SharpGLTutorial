#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include"../VertexFormat.h"
#include <iostream>
#include <vector>
#include "glm/glm.hpp"

namespace Rendering
{
	namespace Models
	{
		class OBJLoader
		{
		public:
			static bool LoadOBJ(const char* path,
				std::vector<VertexFormat>& out_vertices);
		};
	}
}