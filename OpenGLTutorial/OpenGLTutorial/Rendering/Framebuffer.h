#pragma once
#include "../Dependencies/glew/glew.h"
#include <iostream>
#include <vector>

namespace Rendering
{
	class Framebuffer
	{
	private:
		GLuint FBO;

		GLuint texture_color;
		GLuint texture_depth;

		std::vector<GLenum> drawbuffer;

	public:
		Framebuffer();
		~Framebuffer();

	private:
		void Destroy();

		void GenerateFBO(unsigned int width, unsigned int height);

		void GenerateColorTexture(unsigned int width, unsigned int height);
		void GenerateDepthTexture(unsigned int width, unsigned int height);

	public:
		const unsigned int& GetColorTexture();
		const unsigned int& GetDepthTexture();

		void Resize(unsigned int width, unsigned int height);

		void Bind();
		void Unbind();
	};
}