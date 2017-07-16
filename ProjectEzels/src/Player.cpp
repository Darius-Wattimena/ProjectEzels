#include "Player.h"

Game* g;
int playerWY;
int playerSY;
int playerDY;
int playerAY;

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

	playerRect.x = frameWidth;
	playerRect.y = 0;
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;

	playerPosition.x = 512;
	playerPosition.y = 384;
	playerPosition.w = frameWidth;
	playerPosition.h = frameHeight;

	playerWY = frameHeight * 3;
	playerSY = 0;
	playerDY = frameHeight * 2;
	playerAY = frameHeight * 1;
}

void Player::handlePlayerKeyEvent(SDL_Event ev, int frame)
{
	switch (ev.key.keysym.sym)
	{
	case SDLK_w:
		changeWalkDirection(UP, playerWY);
		moveUp(frame);
		break;
	case SDLK_s:
		changeWalkDirection(DOWN, playerSY);
		moveDown(frame);
		break;
	case SDLK_a:
		changeWalkDirection(LEFT, playerAY);
		moveLeft(frame);
		break;
	case SDLK_d:
		changeWalkDirection(RIGHT, playerDY);
		moveRight(frame);
		break;
	}
}

void Player::updatePlayerTexture(int frame)
{
	if (frame > 15) {
		g->resetFrame();

		playerRect.x += frameWidth;

		if (playerRect.x >= textureWidth) {
			playerRect.x = 0;
		}

		motionUsed++;

		if (motionUsed >= 4) {
			motionUsed = 1;
		}
	}
}

void Player::changeWalkDirection(WALK_SIDE walkSide, int playerTextureY)
{
	currentWalkSide = walkSide;
	playerRect.y = playerTextureY;
}

void Player::moveUp(int frame)
{
	playerPosition.y -= 1;
	updatePlayerTexture(frame);
	
}

void Player::moveDown(int frame)
{
	playerPosition.y += 1;
	updatePlayerTexture(frame);
}

void Player::moveLeft(int frame)
{
	playerPosition.x -= 1;
	updatePlayerTexture(frame);
}

void Player::moveRight(int frame)
{
	playerPosition.x += 1;
	updatePlayerTexture(frame);
}
