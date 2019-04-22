#include "pch.h"
#include "Ball.h"


Ball::Ball(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va, const glm::vec2& startPos)
{
    if (!BallModel::isCreated())
        BallModel::generateModel();

    RP_LOG("Ball created");
    m_modelShader = shader;
    m_modelVertexArray = va;
    velocity = 0.005f;
    m_position = startPos;
    m_positionDisplacement = glm::vec2(0.0f, 0.0f);
    m_transformMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(m_position.x, m_position.y, 0.0f));
}


void Ball::setPosition(const glm::vec2& pos)
{
    m_position = pos;
    m_transformMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(m_position.x, m_position.y, 0.0f));
}


void Ball::moveTo(const glm::vec2& pos)
{
    m_positionDisplacement = pos * velocity;
}


void Ball::render()
{
    glm::vec2 tmpVec = m_position + m_positionDisplacement;
    setPosition(tmpVec);
    m_modelShader.get()->setUniform("u_playerTransform", m_transformMatrix);
    Renderer::draw(m_modelVertexArray, m_modelShader);
}
