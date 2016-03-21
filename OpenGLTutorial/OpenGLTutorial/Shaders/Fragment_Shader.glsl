#version 450 core
layout(location = 0) out vec4 out_color;

in vec4 color;
in vec3 normal;

uniform float time;

void main( void )
{
	//out_color = dot(normal, normalize(-vec3(sin(time), -0.5, -0.5))) * color + 0.4 * vec4(0.1, 0.3, 0.1, 1);
	out_color = dot(normal, normalize(-vec3(-0.75, -1.0, -0.5))) * vec4(1, 1, 1, 1) + 0.4 * vec4(0.1, 0.3, 0.1, 1);
	//out_color = vec4(normal, 1);
}