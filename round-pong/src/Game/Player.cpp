#include "pch.h"
#include "Player.h"


Player::Player(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> va, double startAngle)
{
    if (!PlayerModel::isCreated())
        PlayerModel::generateModel();

    RP_LOG("Player created");
    m_modelShader = shader;
    m_modelVertexArray = va;
    m_rotationAngle = 0.0;
    m_angleIncrement = float(PlayerModel::maxPositionAngle / 10.0);
    m_transformMatrix = PlayerModel::identityMat4;
    setPosition(startAngle);
}


void Player::setPosition(double angle)
{
    m_rotationAngle = float(angle);
    m_transformMatrix = glm::rotate(PlayerModel::identityMat4, m_rotationAngle, PlayerModel::rotationUnitVector);
}


void Player::goUp()
{
    double newAngle = m_rotationAngle + m_angleIncrement;
    if (newAngle < PlayerModel::maxPositionAngle)
    {
        setPosition(newAngle);
    }
    else
    {
        setPosition(PlayerModel::maxPositionAngle);
    }
}


void Player::goDown()
{
    double newAngle = m_rotationAngle - m_angleIncrement;
    if (newAngle > PlayerModel::minPositionAngle)
    {
        setPosition(newAngle);
    }
    else
    {
        setPosition(PlayerModel::minPositionAngle);
    }
}


void Player::render()
{
    m_modelShader.get()->setUniform("u_playerTransform", m_transformMatrix);
    Renderer::draw(m_modelVertexArray, m_modelShader);
}
