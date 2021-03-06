#pragma once

#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

namespace Managers
{
	class Shader_Manager
	{
	public:
		Shader_Manager(void);
		~Shader_Manager(void);

		static void CreateProgram(const std::string& shaderName, const std::string& VertexShaderFilename, const std::string& FragmentShaderFilename);

		static const GLuint GetShader(const std::string&);

	private:
		static std::string ReadShader(const std::string& filename);

		static GLuint CreateShader(GLenum shaderType, const std::string& source, const std::string& shaderName);

		static std::map<std::string, GLuint> programs;
	};
}