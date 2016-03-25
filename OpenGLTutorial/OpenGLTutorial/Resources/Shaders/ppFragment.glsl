//blur fragment shader
#version 450 core

layout(location = 0) out vec4 out_color;

const float weights[5] = float[] (0.152781, 0.144599, 0.122589, 0.093095, 0.063327);

const vec3 ambientCol = vec3(0.1, 0.3, 0.1);
const vec3 fogCol = vec3(0.5, 0.9, 0.3);

uniform sampler2D texture_color;
uniform sampler2D texture_depth; 

uniform float time;
uniform int pass = 0;

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
	vec4 color = texture(texture_color, uv).rgba;
	float depth;

	vec3 blur = color.rgb * weights[0];
	float pixelOffset = 3.0;
	vec2 offset;

	if (pass == 0)
	{
		depth = texture(texture_depth, uv).r;

		offset = vec2(pixelOffset / screen_width, 0);
	}
	else
	{
		depth = color.a;

		offset = vec2(0, pixelOffset / screen_height);
	}

	for (int i = 1; i < 5; i++)
	{
		vec3 col = texture(texture_color, uv + i * offset).rgb + 
					texture(texture_color, uv - i * offset).rgb;
		blur += weights[i] * col;
	}
	
	float dof = clamp(2 * (0.8 - pow(depth, 16)), 0, 1);
	

	if (pass == 0)
	{
		out_color = vec4((1 - dof) * blur + dof * color.rgb, depth);
	}
	else
	{
		out_color = vec4(pow((1 - dof) * blur + dof * color.rgb, vec3(1.0 / 1.8)), depth);
	}
}