#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "../Dependencies/freeglut/glut.h"
#include <iostream>

namespace Rendering
{
	class BMPLoader
	{
	public:
		static GLuint LoadBMP(const char* path);
	};
}