#include "pch.h"
#include "Player.h"


std::vector<float> Player::modelVertices;
std::vector<unsigned int> Player::modelIndecies;

bool Player::isModelGenerated = false;
const double Player::modelThickness = 0.09;
const double Player::modelSizeAngle = M_PI / 6.0;

glm::mat4 Player::identityMat4 = glm::mat4(1.0f);
glm::vec3 Player::rotationUnitVector = glm::vec3(0.0, 0.0, 1.0);


void Player::generateModel()
{
    if (isModelGenerated) return;
    RP_LOG("Generating triangles for player");

    const double segmentSizeAngle = M_PI / 32.0;
    const size_t numOfSegments = static_cast<size_t>(std::ceil(modelSizeAngle / segmentSizeAngle));
    const double outerRadius = 0.99;
    const double innerRadius = outerRadius - modelThickness;
    const double angleInc = modelSizeAngle / static_cast<double>(numOfSegments);

    //using literals of type long to avoid warnings
    modelVertices.reserve((numOfSegments + 1l) * 2l * 2l);
    modelIndecies.reserve(numOfSegments * 6l);

    double startAngle = -(modelSizeAngle / 2.0);
    float tmpX, tmpY;
    double tmpSin, tmpCos;

    for (size_t i = 0; i < numOfSegments + 1; i++)
    {
        tmpCos = std::cos(startAngle);
        tmpSin = std::sin(startAngle);

        tmpX = static_cast<float>(tmpCos * innerRadius);
        tmpY = static_cast<float>(tmpSin * innerRadius);
        modelVertices.push_back(tmpX);
        modelVertices.push_back(tmpY);

        tmpX = static_cast<float>(tmpCos * outerRadius);
        tmpY = static_cast<float>(tmpSin * outerRadius);
        modelVertices.push_back(tmpX);
        modelVertices.push_back(tmpY);

        startAngle += angleInc;
    }

    for (size_t i = 0; i < numOfSegments * 2; i++)
    {
        modelIndecies.push_back(static_cast<unsigned int>(i));
        modelIndecies.push_back(static_cast<unsigned int>(i + 1));
        modelIndecies.push_back(static_cast<unsigned int>(i + 2));
    }

    isModelGenerated = true;
}


std::vector<float>& Player::getVertices()
{
    return Player::modelVertices;
}


std::vector<unsigned int>& Player::getIndecies()
{
    return Player::modelIndecies;
}


Player::Player(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va, double startAngle)
{
    if (!isModelGenerated)
        generateModel();

    RP_LOG("Player created");
    m_modelShader = shader;
    m_modelVertexArray = va;
    m_rotationAngle = 0.0;
    m_transformMatrix = identityMat4;
    setPosition(startAngle);
}


void Player::setPosition(double angle)
{
    m_rotationAngle = float(angle);
    m_transformMatrix = glm::rotate(identityMat4, m_rotationAngle, rotationUnitVector);
}


void Player::render()
{
    m_modelShader.get()->setUniform("u_playerTransform", m_transformMatrix);
    Renderer::draw(m_modelVertexArray, m_modelShader);
}
