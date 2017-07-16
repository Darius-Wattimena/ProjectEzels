#include "SDL.h"
#include "SDL_image.h"

#include "Game.h"
#include "Map.h"
#include "Player.h"


SDL_Event ev;
MainWindow mw;
Player player = nullptr;
Map map = nullptr;

int frame = 0;

Game::Game(MainWindow mainWindow)
{
	mw = mainWindow;

	player = Player(this);
	player.loadPlayerTexture("res/player.png");

	map = Map(this);
	map.loadMapTexture("res/map.png");

	while (mw.isRunning()) {

		frame++;

		while (SDL_PollEvent(&ev) != 0) {
			handleEvent();
		}

		if (player.motionUsed != 1) {
			switch (player.currentWalkSide) {
			case Player::UP:
				player.moveUp(frame, map);
				break;
			case Player::DOWN:
				player.moveDown(frame, map);
				break;
			case Player::LEFT:
				player.moveLeft(frame, map);
				break;
			case Player::RIGHT:
				player.moveRight(frame, map);
				break;
			}
		}

		SDL_RenderClear(mw.renderer);
		SDL_RenderCopy(mw.renderer, map.mapTexture, NULL, NULL);
		SDL_RenderCopy(mw.renderer, player.playerTexture, &player.playerRect, &player.playerPosition);
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
		player.clearPlayer();
		mw.stopRunning();
		mw.close();
	}
	else if (ev.type == SDL_KEYDOWN) {
		handleKeyEvent();
	}
	else if (ev.type == SDL_KEYUP) {
		player.handlePlayerKeyUpEvent(ev);
	}
}

void Game::handleKeyEvent()
{
	if (player.motionUsed == 1) {
		player.handlePlayerKeyDownEvent(ev, frame, map);
	}
}

void Game::resetFrame()
{
	frame = 0;
}
