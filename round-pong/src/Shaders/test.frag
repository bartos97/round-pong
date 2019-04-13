#version 330 core

uniform vec4 uniformColor;
out vec4 fragmentColor;

void main()
{
    fragmentColor = uniformColor;
}