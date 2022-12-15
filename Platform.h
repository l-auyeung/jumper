#pragma once
#include "Constants.h"
class Platform
{
public:
	Platform(Texture* texture, Vector2f size, Vector2f position);
	~Platform();

	void Draw(RenderWindow& window);
	FloatRect GetHitbox();
	Vector2f GetPosition();
	Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	RectangleShape body;
};

