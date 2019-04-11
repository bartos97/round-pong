#version 330 core

layout (location = 0) in vec2 attrPos;

uniform float uniformPos;

void main()
{
    gl_Position = vec4(attrPos.x + uniformPos, attrPos.y + uniformPos, 0.0, 1.0);
}