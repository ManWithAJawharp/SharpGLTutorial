#version 450 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;
layout(location = 2) in vec3 in_normal;

uniform mat4 projection_matrix, view_matrix, model_matrix;
uniform float time;

out vec4 color;
out vec3 normal;

void main( void )
{
	color = in_color;
	normal = normalize(in_normal);
	//vec4 pos = projection_matrix * view_matrix * model_matrix * vec4(in_position, 1.0);
	gl_Position = projection_matrix * view_matrix * model_matrix * vec4(in_position, 1.0);
}