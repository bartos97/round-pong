#pragma once

#include "OpenGL/VertexArray.h"
#include "OpenGL/Shader.h"


class Renderer
{
public:
    void draw(const VertexArray& va, const Shader& shader);
    void clearScreen() const;
};