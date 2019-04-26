#pragma once
#include "OpenGL/Renderer.h"
#include "PlayerModel.h"


class Player
{
public:
    Player(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va, double startAngle);
    
    void setPosition(double angle);
    void setPosition(float angle);
    void goUp();
    void goDown();
    void render();

private:    
    std::shared_ptr<Shader> m_modelShader;
    std::shared_ptr<VertexArray> m_modelVertexArray;

    float m_rotationAngle;
    float m_angleIncrement;
    glm::mat4 m_transformMatrix;
};

