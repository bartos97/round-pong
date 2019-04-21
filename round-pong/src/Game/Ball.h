#pragma once
#include "Renderer.h"
#include "BallModel.h"


class Ball
{
public:
    Ball(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va);

    void setPosition(const glm::vec2& pos);
    void render();

private:
    std::shared_ptr<Shader> m_modelShader;
    std::shared_ptr<VertexArray> m_modelVertexArray;

    glm::vec2 m_position;
    glm::mat4 m_transformMatrix;
};
