#version 430 core

layout (location = 0) in vec2 attrPos;

uniform mat4 u_playerTransform;

void main()
{
//    gl_Position = vec4(attrPos.x, attrPos.y, 0.0, 1.0);
    gl_Position = u_playerTransform * vec4(attrPos.x, attrPos.y, 0.0, 1.0);
}