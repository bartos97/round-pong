#pragma once
#include "Renderer.h"
#include "BallModel.h"


class Ball
{
public:
    Ball(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va, const glm::vec2& startPos);

    void render();
    void setPosition(const glm::vec2& pos);
    void moveTo(const glm::vec2& pos);

private:
    std::shared_ptr<Shader> m_modelShader;
    std::shared_ptr<VertexArray> m_modelVertexArray;

    float velocity;
    glm::vec2 m_position;
    glm::vec2 m_positionDisplacement;
    glm::mat4 m_transformMatrix;

    glm::vec2 generateRandomVector();
};
