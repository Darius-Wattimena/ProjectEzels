#pragma once

#include "Game.h"

class Player {
public:
	Player::Player(Game* game);
	SDL_Rect playerRect;
	SDL_Texture *playerTexture;
	void clearPlayer();
	void loadPlayerTexture(std::string filePath);
	int textureWidth;
	int textureHeight;
	int frameWidth;
	int	frameHeight;
};