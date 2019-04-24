#pragma once
#include "Renderer.h"
#include "BallModel.h"


class Ball
{
public:
    Ball(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va, const glm::vec2& startPos);

    void render();
    inline void setPosition(const glm::vec2& newPosition);
    void moveTo(const glm::vec2& newPosition);

private:
    static const glm::mat4 identityMat4;
    std::shared_ptr<Shader> m_modelShader;
    std::shared_ptr<VertexArray> m_modelVertexArray;

    float m_velocity;
    glm::vec2 m_position;
    glm::vec2 m_positionDisplacement;
    glm::mat4 m_transformMatrix;


    glm::vec2 generateRandomVector();
};
