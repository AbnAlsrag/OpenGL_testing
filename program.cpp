#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glad/glad.h>
#include <iostream>
#include <vector>

#include "Graphic/Window.hpp"
#include "Core/Entity.hpp"
#include "Core/Player.hpp"
#include "Physics/Collision.hpp"
#include "Utils/Utils.hpp"


int main(int argc, char* args[])
{
	Window window("NAQH Engine", 1280, 720);
	const Uint8 *keyState = SDL_GetKeyboardState(NULL);
	
	const float timeStep = 1/60;
	float accumulator;
	float currentTime = Utils::hireTimeInSecond();

	Vector2 obsPosition;
	Vector2 knightPosition(30, 100), knightFramePosition(0, 0), knightVelocity(0.3, 0.1);
	bool isGrounded;
	bool isCollided;

	SDL_Color white = { 255, 255, 255 };
	SDL_Color black = { 0, 0, 0 };
	TTF_Font* font48 = TTF_OpenFont("res/font/font.ttf", 48);
	TTF_Font* font72 = TTF_OpenFont("res/font/font.ttf", 72);

	SDL_Texture* grassTexture = window.LoadTexture("res/texture/ground_grass_1.png");
	SDL_Texture* Atlas = window.LoadTexture("res/texture/Atlas_Blocks.png");
	SDL_Texture* knightTexture = window.LoadTexture("res/texture/knight.png");
	window.DrawColor(195, 195, 195);

	std::vector<Entity> entitiees = {Entity(Vector2(0, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*2, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*3, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*4, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*5, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*6, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*7, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*8, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*9, 150), Vector2(32, 32), Vector2(0, 0), Atlas),
									Entity(Vector2(32*10, 150), Vector2(32, 32), Vector2(0, 0), Atlas)};

	std::vector<Entity> obs = {Entity(Vector2(50, 50), Vector2(32, 32), Vector2(0, 0), Atlas),
							  Entity(Vector2(50+32, 50), Vector2(32, 32), Vector2(32, 0), Atlas),
							  Entity(Vector2(50+64, 50), Vector2(32, 32), Vector2(64, 0), Atlas)};

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		//عقبات

		//اللاعب
		Entity knight(knightPosition, Vector2(64, 64), Vector2(0, 0), knightTexture);

		if (keyState[SDL_SCANCODE_RIGHT])
			knightPosition.x += knightVelocity.x * 0.2;
		else if (keyState[SDL_SCANCODE_LEFT])
			knightPosition.x -= knightVelocity.x * 0.2;
		else
			knightPosition.x += 0;

		if (keyState[SDL_SCANCODE_UP])
			knightPosition.y -= knightVelocity.y;
		else if (keyState[SDL_SCANCODE_DOWN] && !isGrounded)
			knightPosition.y += knightVelocity.y;
	
		//تصادم

		if (isCollided)
		{
			//knightVelocity.x = 0;
		}

		if (checkCollision(knightPosition.x, knightPosition.y, 40, 55, obsPosition.x, obsPosition.y, 16, 16))
		{
			isCollided = true;
		}

		if (knightPosition.y >= 100)
		{
			isGrounded = true;
		}
		else if (knightPosition.y < 100)
		{
			
			isGrounded = false;
		}

		if (knightPosition.x <= -20)
			knightPosition.x = -20;
		else if (knightPosition.x >=  271)
			knightPosition.x = 271;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.Clear();
		
		for (Entity& e : obs)
		{ 
			obsPosition = e.getPosition();
			window.Render(e);
		}
		
		window.Render(knight);


		for (Entity& e : entitiees)
		{
			window.Render(e);
		}

		window.Display();
	}

	window.CleanUp();
	SDL_Quit();

	return 0;
}