#version 450 core
layout(location = 1) out vec3 color;

in vec2 uv;
in vec3 normal;
in vec3 viewDirection;

uniform float time;
uniform sampler2D textureSampler;

void main( void )
{
	//vec3 lightDirection = normalize(vec3(cos(time), -1, sin(time)));
	vec3 lightDirection = normalize(vec3(1, -3, 2));

	float specular = clamp(dot(reflect(viewDirection, normal), lightDirection), 0, 1);

	//out_color = clamp(dot(-normal, normalize(lightDirection)), 0, 1) * texture(textureSampler, uv + vec2(0, 0.5 * sin(time + 4 * uv.x))) + 0.4 * vec4(0.1, 0.3, 0.1, 1);
	color = clamp(dot(-normal, normalize(lightDirection)), 0, 1) * texture(textureSampler, uv).rgb + 0.4 * vec3(0.1, 0.3, 0.1) + 0.5 * pow(specular, 8);
}