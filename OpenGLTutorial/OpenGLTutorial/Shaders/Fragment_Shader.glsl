#version 450 core
layout(location = 0) out vec4 out_color;

in vec4 color;
in vec3 normal;

void main( void )
{
	out_color = dot(normal, vec3(0, 1, 0.5)) * color;
}