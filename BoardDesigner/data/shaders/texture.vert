#version 450

#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec2 inUV;

layout (binding = 0) uniform UBO
{
	mat4 projection;
	mat4 model;
	//vec4 viewPos;
	float lodBias;
} ubo;

layout (location = 0) out vec2 outUV;
layout (location = 1) out float outLodBias;

out gl_PerVertex
{
	vec4 gl_Position;
};

void main()
{
	outUV = inUV;
	outLodBias = ubo.lodBias;
	
	//vec3 worldPos = vec3(ubo.model * vec4(inPos, 1.0));
	
	gl_Position = ubo.projection * ubo.model * vec4(inPos.xyz, 1.0);
	
}