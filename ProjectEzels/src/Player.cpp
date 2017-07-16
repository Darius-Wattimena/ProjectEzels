#include "Player.h"

Game* playerGame;
int playerWY;
int playerSY;
int playerDY;
int playerAY;

Player::Player(Game* game)
{
	playerGame = game;
}

void Player::clearPlayer()
{
	SDL_DestroyTexture(playerTexture);
}

void Player::loadPlayerTexture(std::string filePath)
{
	playerTexture = playerGame->loadTexture(filePath);

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

	running = false;
}

void Player::handlePlayerKeyDownEvent(SDL_Event ev, int frame, Map map)
{
	switch (ev.key.keysym.sym)
	{
	case SDLK_LSHIFT:
		startRunning();
		break;
	case SDLK_w:
		changeWalkDirection(UP, playerWY);
		moveUp(frame, map);
		break;
	case SDLK_s:
		changeWalkDirection(DOWN, playerSY);
		moveDown(frame, map);
		break;
	case SDLK_a:
		changeWalkDirection(LEFT, playerAY);
		moveLeft(frame, map);
		break;
	case SDLK_d:
		changeWalkDirection(RIGHT, playerDY);
		moveRight(frame, map);
		break;
	}
}

void Player::handlePlayerKeyUpEvent(SDL_Event ev)
{
	switch (ev.key.keysym.sym)
	{
	case SDLK_LSHIFT:
		stopRunning();
		break;
	}
}

void Player::updatePlayerTexture(int frame)
{
	if (running) {
		if (frame > 7) {
			playerGame->resetFrame();

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
	else {
		if (frame > 15) {
			playerGame->resetFrame();

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
}

void Player::changeWalkDirection(WALK_SIDE walkSide, int playerTextureY)
{
	currentWalkSide = walkSide;
	playerRect.y = playerTextureY;
}

void Player::startRunning()
{
	running = true;
}

void Player::stopRunning()
{
	running = false;
}

void Player::moveUp(int frame, Map map)
{
	if (!playerPosition.y <= 0) {
		if (running) {
			playerPosition.y -= 2;
		}
		else {
			playerPosition.y -= 1;
		}
		updatePlayerTexture(frame);
	}
	else
	{
		motionUsed = 1;
	}
}

void Player::moveDown(int frame, Map map)
{
	if (playerPosition.y < map.mapHeight) {
		if (running) {
			playerPosition.y += 2;
		}
		else {
			playerPosition.y += 1;
		}
		updatePlayerTexture(frame);
	}
	else
	{
		motionUsed = 1;
	}
}

void Player::moveLeft(int frame, Map map)
{
	if (!playerPosition.x <= 0) {
		if (running) {
			playerPosition.x -= 2;
		}
		else {
			playerPosition.x -= 1;
		}
		updatePlayerTexture(frame);
	}
	else 
	{
		motionUsed = 1;
	}
}

void Player::moveRight(int frame, Map map)
{
	if (playerPosition.x < map.mapWidth) {
		if (running) {
			playerPosition.x += 2;
		}
		else {
			playerPosition.x += 1;
		}
		updatePlayerTexture(frame);
	}
	else
	{
		motionUsed = 1;
	}
}
