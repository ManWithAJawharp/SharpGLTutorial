#pragma once
#include "../Dependencies/glew/glew.h"
#include "BMP_Header.h"
#include <fstream>
#include <iostream>
#include <string>

namespace Rendering
{
	class TextureLoader
	{
	public:
		TextureLoader();
		~TextureLoader();

		static unsigned int LoadTexture(const std::string& filename,
			unsigned int width,
			unsigned int height);

	private:

		static void LoadBMPFile(const std::string& filename,
			unsigned int& width,
			unsigned int& height,
			unsigned char*& data);
	};



}