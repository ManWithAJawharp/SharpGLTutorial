#version 450 core
layout(location = 0) out vec4 out_color;

in vec4 color;
in vec3 normal;

uniform float time;

void main( void )
{
	out_color = dot(normal, normalize(-vec3(sin(time), -1, -1))) * color + 0.4 * vec4(0.1, 0.3, 0.1, 1);
	//out_color = color;
}