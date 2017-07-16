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

	running = false;
}

void Player::handlePlayerKeyDownEvent(SDL_Event ev, int frame)
{
	switch (ev.key.keysym.sym)
	{
	case SDLK_LSHIFT:
		startRunning();
		break;
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
	else {
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

void Player::moveUp(int frame)
{
	if (running) {
		playerPosition.y -= 2;
	}
	else {
		playerPosition.y -= 1;
	}
	updatePlayerTexture(frame);
	
}

void Player::moveDown(int frame)
{
	if (running) {
		playerPosition.y += 2;
	}
	else {
		playerPosition.y += 1;
	}
	updatePlayerTexture(frame);
}

void Player::moveLeft(int frame)
{
	if (running) {
		playerPosition.x -= 2;
	}
	else {
		playerPosition.x -= 1;
	}
	updatePlayerTexture(frame);
}

void Player::moveRight(int frame)
{
	if (running) {
		playerPosition.x += 2;
	}
	else {
		playerPosition.x += 1;
	}
	updatePlayerTexture(frame);
}
