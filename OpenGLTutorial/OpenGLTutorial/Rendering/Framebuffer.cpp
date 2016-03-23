#include "Framebuffer.h"

using namespace Rendering;

Framebuffer::Framebuffer()
{

}

Framebuffer::~Framebuffer()
{
	Destroy();
}

void Framebuffer::Destroy()
{
	glDeleteFramebuffers(1, &FBO);
	glDeleteTextures(1, &texture_color);
	glDeleteTextures(1, &texture_depth);
}

void Framebuffer::GenerateFBO(unsigned int width, unsigned int height)
{
	glGenFramebuffers(1, &FBO);                     //Generate a framebuffer object(FBO)
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);         // and bind it to the pipeline

	GenerateColorTexture(width, height);//generate empty texture
	GenerateDepthTexture(width, height);//generate empty texture

	unsigned int attachment_index_color_texture = 0;   //to keep track of our textures
													   //bind textures to pipeline. texture_depth is optional .0 is the mipmap level. 0 is the heightest
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + attachment_index_color_texture, texture_color, 0);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, texture_depth, 0);//optional

	drawbuffer.push_back(GL_COLOR_ATTACHMENT0 + attachment_index_color_texture);    //add attachements
	glDrawBuffers(drawbuffer.size(), &drawbuffer[0]);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {  //Check for FBO completeness
		std::cout << "Error! FrameBuffer is not complete" << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);    //unbind framebuffer
}

void Framebuffer::GenerateColorTexture(unsigned int width, unsigned int height)
{
	glGenTextures(1, &texture_color);
	glBindTexture(GL_TEXTURE_2D, texture_color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
}

void Framebuffer::GenerateDepthTexture(unsigned int width, unsigned int height)
{
	glGenTextures(1, &texture_depth);
	glBindTexture(GL_TEXTURE_2D, texture_depth);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
}

const unsigned int& Framebuffer::GetColorTexture()
{
	return texture_color;
}

const unsigned int& Framebuffer::GetDepthTexture()
{
	return texture_depth;
}

void Framebuffer::Resize(unsigned int width, unsigned int height)
{
	Destroy();
	GenerateFBO(width, height);
}

void Framebuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
}

void Framebuffer::Unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}