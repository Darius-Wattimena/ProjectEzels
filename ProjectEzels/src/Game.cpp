#include "SDL.h"
#include "SDL_image.h"

#include "Game.h"
#include "MainWindow.h"
#include "Player.h"
#include "CustomException.h"

SDL_Event ev;
MainWindow mw;
Player player = nullptr;

Game::Game(MainWindow mainWindow)
{
	mw = mainWindow;
	int frame = 0;
	int FPS = 60;

	player = Player(this);
	player.loadPlayerTexture("res/player.png");

	while (mw.isRunning()) {

		while (SDL_PollEvent(&ev) != 0) {
			handleEvent();
		}

		frame++;

		if (FPS / frame == 4) {
			frame = 0;
			player.playerRect.x += player.frameWidth;

			if (player.playerRect.x >= player.textureWidth) {
				player.playerRect.x = 0;
			}
		}

		SDL_RenderClear(mw.renderer);
		SDL_RenderCopy(mw.renderer, player.playerTexture, &player.playerRect, NULL);
		SDL_RenderPresent(mw.renderer);
	}
}

SDL_Surface* Game::loadSurface(std::string filePath)
{
	SDL_Surface *convertedSurface = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());
	
	if (surface == NULL) {
		throw CustomException(_CRT_WIDE(__FILE__), __LINE__, L"Error loading file surface");
	}

	convertedSurface = SDL_ConvertSurface(surface, mw.windowSurface->format, 0);

	if (convertedSurface == NULL) {
		throw CustomException(_CRT_WIDE(__FILE__), __LINE__, L"Error converting surface to windowSurface");
	}

	SDL_FreeSurface(surface);

	return convertedSurface;
}

SDL_Texture * Game::loadTexture(std::string filePath)
{
	SDL_Texture *texture = IMG_LoadTexture(mw.renderer, filePath.c_str());

	if (texture == NULL) {
		throw CustomException(_CRT_WIDE(__FILE__), __LINE__, L"Error creating texture from surface");
	}

	return texture;
}

void Game::handleEvent()
{
	if (ev.type == SDL_QUIT) {
		mw.stopRunning();
		mw.close();
	}
	else if (ev.type == SDL_KEYDOWN) {
		handleKeyEvent();
	}
}

void Game::handleKeyEvent()
{
	switch (ev.key.keysym.sym)
	{
	case SDLK_w:
		player.playerRect.y = player.frameHeight * 3;
		break;
	case SDLK_s:
		player.playerRect.y = 0;
		break;
	case SDLK_a:
		player.playerRect.y = player.frameHeight * 1;
		break;
	case SDLK_d:
		player.playerRect.y = player.frameHeight * 2;
		break;
	default:
		break;
	}
}
