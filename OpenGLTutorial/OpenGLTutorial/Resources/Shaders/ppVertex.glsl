#version 450 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_uv;
layout(location = 2) in vec3 in_normal;

out vec2 uv;

void main( void )
{
	uv = in_uv;

	gl_Position = vec4(in_position, 1);
}