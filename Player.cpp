#include "Player.h"

Player::Player(Texture* texture, float speed, float jumpHeight)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;

	body.setSize(Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
	body.setOrigin(Vector2f((body.getSize().x / 1.5f), (body.getSize().y)));
	//body.setOrigin(body.getSize() / 4.0f);
	body.setPosition(PLAYER_START_X, PLAYER_START_Y);
	body.setTexture(texture);
	
}

Player::~Player() {}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f; //no acceleration allowed >:)
	//horizontal movement
	if (Keyboard::isKeyPressed(Keyboard::A))
		velocity.x -= speed;
	if (Keyboard::isKeyPressed(Keyboard::D))
		velocity.x += speed;

	velocity.y += 981.0f * deltaTime; //effect of gravity

	if (velocity.y > 0) { }

	body.move(velocity * deltaTime);
	//maybe add jump collision here and jump?
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}

Vector2f Player::GetPosition() { return body.getPosition(); } //returns the top left corner of the player rectangle

void Player::OnCollision()
{
	
	//falling down
	velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
	
	
}

FloatRect Player::GetHitbox()
{
	return body.getGlobalBounds();
}

void Player::stopY()
{
	body.move(0.0f, 0.0f);
}

void Player::Move(float yMove)
{
	body.move(0.0f, yMove);
}

float Player::getY()
{
	return velocity.y;
}