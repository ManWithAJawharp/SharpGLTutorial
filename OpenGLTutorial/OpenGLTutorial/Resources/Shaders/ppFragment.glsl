//blur fragment shader
#version 450 core

layout(location = 0) out vec3 out_color;

const float weights[4] = float[] (0.726, 0.278, 0.055, 0.005);

const vec3 ambientCol = vec3(0.1, 0.3, 0.1);
const vec3 fogCol = vec3(0.5, 0.9, 0.3);

uniform sampler2D texture_color;
uniform sampler2D texture_depth; 

uniform float time;

uniform mat4 i_pv_matrix;

uniform int screen_width, screen_height;

in vec2 uv;

/*void main()
{
	float depth = texture(texture_depth, uv).r;
	vec4 worldPosition = i_pv_matrix * vec4(uv * 2 - 1, depth, 1);
	worldPosition /= worldPosition.w;

	vec3 col = texture(texture_color, uv).rgb;

	float fogHeight = 2 + 0.5 * sin(time);

	float fog =  0.5 * clamp(fogHeight - worldPosition.y, 0, fogHeight);
	float distanceFog = pow(depth, 48);

	float totalFog = max(fog, distanceFog) - 0.2;

	out_color = totalFog * fogCol + (1 - totalFog) * col;
}*/

void main()
{
	vec3 col = texture(texture_color, uv).rgb;
	float depth = clamp(0.5 - pow(texture(texture_depth, uv).r, 32), 0, 1);

	float offset = depth * 10.0 / screen_width;
	vec3 blur = depth * col;
	for (int i = 0; i < 4; i++)
	{
		blur += depth * texture(texture_color, uv + vec2(offset * i, 0)).rgb * weights[i];
		blur += depth * texture(texture_color, uv + vec2(- offset * i, 0)).rgb * weights[i];
	}

	//blur /= 11;

	out_color = blur;
}