#pragma once

class Room
{
private:
	sf::RectangleShape m_shape;
	//std::vector<SceneObject> m_roomObjects;
public:
	Room(const sf::Vector2f& position = { 0, 0 }, const sf::Vector2f& size = { 1366, 768 });
	~Room();

	void update(const float& deltaTime);
	void draw(sf::RenderWindow& window) const;
};