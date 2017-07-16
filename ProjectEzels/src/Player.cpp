#include "Player.h"

Game* g;

Player::Player(Game* game)
{
	g = game;
}

void Player::clearPlayer()
{
	SDL_DestroyTexture(playerTexture);
}

void Player::loadPlayerTexture(std::string filePath)
{
	playerTexture = g->loadTexture(filePath);

	SDL_QueryTexture(playerTexture, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / 3;
	frameHeight = textureHeight / 4;

	playerRect.x = 0;
	playerRect.y = 0;
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;
}
