#include "pch.h"
#include "Ball.h"

Ball::Ball(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va)
{
    if (!BallModel::isCreated())
        BallModel::generateModel();

    RP_LOG("Ball created");
    m_modelShader = shader;
    m_modelVertexArray = va;
}

void Ball::render()
{
    m_modelShader.get()->setUniform("u_playerTransform", glm::mat4(1.0f));
    Renderer::draw(m_modelVertexArray, m_modelShader);
}
