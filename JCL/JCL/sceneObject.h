#pragma once

class SceneObject
{
protected:
	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
public:
	bool isDead;

	SceneObject(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 10, 10 });
	virtual ~SceneObject() {};

	virtual sf::Vector2f getPosition() const;
	virtual void setPosition(const sf::Vector2f& position);

	virtual void update(const float& deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) const;
};