#include "Constants.h"
#include "Player.h"
#include "Platform.h"

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "jumpingGame", Style::Default);

	Texture playerTexture;
	Texture platTexture;
	playerTexture.loadFromFile(PLAYER_TEXTURE);
	// platTexture.loadFromFile(PLAT_TEXTURE);
	

	View view(Vector2f(0.0f, 0.0f), Vector2f(512.0f, 512.0f));
	
	Player player(&playerTexture, PLAYER_SPEED, PLAYER_JUMP_HEIGHT);

	vector<Platform> platforms;
	Platform plat1(nullptr, Vector2f(PLAT_WIDTH, PLAT_HEIGHT), Vector2f(350.0f, 150.0f));
	Platform plat2(nullptr, Vector2f(PLAT_WIDTH, PLAT_HEIGHT), Vector2f(150.0f, 350.0f));
	Platform ground(nullptr, Vector2f(1000.0f, 200.0f), Vector2f(500.0f, 500.0f));
	platforms.push_back(plat1);
	platforms.push_back(plat2);
	platforms.push_back(ground);

	float deltaTime = 0.0f;
	Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}
		player.Update(deltaTime);
		FloatRect pCol = player.GetHitbox();

		for (int i = 0; i < platforms.size(); i++)
		{
			if (platforms[i].GetHitbox().intersects(pCol) && player.getY() > 0)
			{
				//i mean... i could make this another class to get it under 50 or take out all the spaces... but i'd be an animal for doing that
				Vector2f Pos = platforms[i].GetPosition() - player.GetPosition();
				float inter = abs(Pos.y) - ((platforms[i].GetHalfSize().y) + player.GetHalfSize().y);
				player.OnCollision();
			}
		}
		
		window.clear(Color(120, 20, 90));
		window.setView(view);

		//drawing
		player.Draw(window);
		//draw all platforms (honestly sick)
		for (Platform& platform : platforms)
			platform.Draw(window);
		view.setCenter(player.GetPosition());
		window.display();
	}
	return 0;

	}