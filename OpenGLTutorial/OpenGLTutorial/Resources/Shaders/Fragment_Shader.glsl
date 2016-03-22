#version 450 core
layout(location = 0) out vec4 out_color;

in vec2 uv;
in vec3 normal;

uniform float time;
uniform sampler2D textureSampler;

void main( void )
{
	//vec3 lightDirection = normalize(vec3(cos(time), -1, sin(time)));
	vec3 lightDirection = normalize(vec3(1, -3, 2));

	out_color = clamp(dot(-normal, normalize(lightDirection)), 0, 1) * texture(textureSampler, uv + vec2(0, 0.5 * sin(time + 4 * uv.x))) + 0.4 * vec4(0.1, 0.3, 0.1, 1);
}