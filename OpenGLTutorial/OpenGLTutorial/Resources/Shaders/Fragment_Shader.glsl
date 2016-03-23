#version 450 core
out vec3 color;

in vec2 uv;
in vec3 normal;
in vec3 viewDirection;

uniform float time;
uniform sampler2D textureSampler;

void main( void )
{
	vec3 lightDirection = normalize(vec3(1, -3, 2));

	float diffuse = clamp(dot(-normal, normalize(lightDirection)), 0, 1);
	float specular = clamp(dot(reflect(viewDirection, normal), lightDirection), 0, 1);
	vec3 ambient = 0.3 * vec3(0.1, 0.3, 0.1);
	float rim = 1 - clamp(dot(normal, viewDirection), 0, 1);

	color = diffuse * texture(textureSampler, uv).rgb + ambient + 0.4 * pow(specular, 16) + 0.25 * pow(rim, 4);
	//color = 0.5 * pow(rim, 4) * vec3(1, 1, 1);
}