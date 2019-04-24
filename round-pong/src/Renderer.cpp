#include "pch.h"
#include "Renderer.h"

void Renderer::draw(const VertexArray & va, const Shader & shader)
{
    va.bind();
    shader.bind();
#ifdef RP_DEBUG
    GL_CALL(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
#endif
    GL_CALL(glDrawElements(GL_TRIANGLES, va.getElementBuffer().getCount(), GL_UNSIGNED_INT, 0));
}


void Renderer::draw(std::shared_ptr<VertexArray> va, std::shared_ptr<Shader> shader)
{
    va.get()->bind();
    shader.get()->bind();
#ifdef RP_DEBUG
    GL_CALL(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
#endif
    GL_CALL(glDrawElements(GL_TRIANGLES, va.get()->getElementBuffer().getCount(), GL_UNSIGNED_INT, 0));
}


void Renderer::clearScreen()
{
    glClearColor(0.16f, 0.16f, 0.16f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
