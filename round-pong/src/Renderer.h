#pragma once

#include "VertexArray.h"
#include "Shader.h"


class Renderer
{
public:
    void draw(const VertexArray& va, const Shader& shader);
    void clearScreen() const;
};