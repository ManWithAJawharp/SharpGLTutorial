//blur fragment shader
#version 450 core

layout(location = 0) out vec4 out_color;

uniform sampler2D texture_color;
uniform sampler2D texture_depth; 

uniform int screen_width, screen_height;

in vec2 uv;

void main()
{
	out_color = texture(texture_color, uv) * vec4(1, 1, 0, 1);
}