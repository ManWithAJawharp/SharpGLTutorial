#version 450 core
layout(location = 0) out vec3 color;

in vec2 uv;
in vec3 normal;
in vec3 viewDirection;
in vec4 worldPos;

const vec3 lightCol = vec3(1.0, 0.9, 0.4);

uniform float time;
uniform sampler2D textureSampler;
uniform sampler2D lightmapSampler;

uniform mat4 projection_matrix;
uniform mat4 lightMatrix;

void main( void )
{
	vec3 lightDirection = normalize(vec3(1, -3, 2));

	float diffuse = 0.5 * ceil(2 * clamp(dot(-normal, normalize(lightDirection)), 0, 1));
	float specular = clamp(dot(reflect(viewDirection, normal), lightDirection), 0, 1);
	float rim = (1 - clamp(dot(normal, viewDirection), 0, 1)) * pow(1 - diffuse, 4);
	vec3 ambient = 0.5 * vec3(0.1, 0.3, 0.1);

	color = (diffuse * texture(textureSampler, uv).rgb + 0.8 * step(0.2, pow(specular, 16))) * lightCol + 0.4 * pow(rim, 4) * lightCol + ambient;
}