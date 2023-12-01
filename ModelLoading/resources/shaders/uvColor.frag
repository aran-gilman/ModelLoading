#version 460 core
out vec4 FragColor;

in vec2 UV;

void main()
{
    FragColor = vec4(abs(UV), 0.0f, 1.0f);
}