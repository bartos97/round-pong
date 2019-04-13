#include "pch.h"
#include "Renderer.h"

void Renderer::draw(const VertexArray & va, const Shader & shader)
{
    va.bind();
    shader.bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, va.getElementBuffer().getCount(), GL_UNSIGNED_INT, 0));
}

void Renderer::clearScreen() const
{
    glClearColor(0.16f, 0.16f, 0.16f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
