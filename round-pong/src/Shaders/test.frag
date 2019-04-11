#version 330 core

uniform vec3 uniformColor;

out vec4 fragmentColor;

void main()
{
    fragmentColor = vec4(uniformColor, 1.0);
}