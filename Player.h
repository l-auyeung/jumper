#pragma once
#include "Constants.h"
class Player
{
public:
	Player(Texture* texture, float speed, float jumpHeight);
	~Player();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);

	Vector2f GetPosition();
	void OnCollision();
	FloatRect GetHitbox();
	void stopY();
	Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
	void Move(float yMove);

private:
	RectangleShape body;
	bool jumping;
	float jumpHeight;
	float speed;

	Vector2f velocity;
};

