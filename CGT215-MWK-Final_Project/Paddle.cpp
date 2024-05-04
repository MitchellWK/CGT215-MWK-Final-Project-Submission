#include "Paddle.h"

Paddle::Paddle(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(20, 100));
	m_Shape.setFillColor(sf::Color::White);
	m_Shape.setOutlineColor(sf::Color::Black);
	m_Shape.setOutlineThickness(3);

	m_Shape.setPosition(m_Position);

}

sf::FloatRect Paddle::getPosition()
{
	return m_Shape.getGlobalBounds();
}
sf::RectangleShape Paddle::getShape()
{
	return m_Shape;
}

void Paddle::moveUp()
{
	m_MovingUp = true;
}

void Paddle::moveDown()
{
	m_MovingDown = true;
}

void Paddle::stopUp()
{
	m_MovingUp = false;
}

void Paddle::stopDown()
{
	m_MovingDown = false;
}

void Paddle::update(sf::Time dt)
{
	if (m_MovingUp)
	{
		m_Position.y -= m_Speed * dt.asSeconds();
	}

	if (m_MovingDown)
	{
		m_Position.y += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}