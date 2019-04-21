#pragma once
#include "Renderer.h"

class Player
{
public:
    Player(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va, double startAngle);
    
    void setPosition(double angle);
    void render();

public:
    static void generateModel();
    static std::vector<float>& getVertices();
    static std::vector<unsigned int>& getIndecies();
    static const double modelThickness;
    static const double modelSizeAngle;

private:
    static bool isModelGenerated;
    static std::vector<float> modelVertices;
    static std::vector<unsigned int> modelIndecies;

    static glm::mat4 identityMat4;
    static glm::vec3 rotationUnitVector;
    
    std::shared_ptr<Shader> m_modelShader;
    std::shared_ptr<VertexArray> m_modelVertexArray;

    float m_rotationAngle;
    glm::mat4 m_transformMatrix;
};

