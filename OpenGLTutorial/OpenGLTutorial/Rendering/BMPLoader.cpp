#include "BMPLoader.h"

using namespace Rendering;

GLuint BMPLoader::LoadBMP(const char* path)
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char* data;

	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		std::cout << "Could not load BMP file " << path << std::endl;
		return 0;
	}

	dataPos = *(int*)& (header[0x0A]);
	imageSize = *(int*)& (header[0x22]);
	width = *(int*)& (header[0x12]);
	height = *(int*)& (header[0x16]);

	if (imageSize == 0)
	{
		std::cout << "No image size found, creating automatically." << std::endl;
		imageSize = width * height * 3;
	}
	if (dataPos == 0)
	{
		std::cout << "No image starting position found, creating automatically." << std::endl;
		dataPos = 54;
	}

	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return textureID;
}