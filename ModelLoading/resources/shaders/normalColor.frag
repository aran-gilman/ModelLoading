#version 460 core
out vec4 FragColor;

in vec3 Normal;

void main()
{
    FragColor = vec4(abs(Normal), 1.0f);
}