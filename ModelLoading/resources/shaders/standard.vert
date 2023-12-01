#version 460 core
layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inNormal;

layout (std140, binding = 0) uniform Camera
{
    mat4 view;
    mat4 projection;
} camera;

out vec3 Normal;

void main()
{
    gl_Position = camera.projection * camera.view * vec4(inPos, 1.0f);
    Normal = inNormal;
}