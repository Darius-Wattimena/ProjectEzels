#pragma once

#include "Game.h"

class Player {
public:
	Player::Player(Game* game);
	SDL_Rect playerRect;
	SDL_Rect playerPosition;
	SDL_Texture *playerTexture;
	bool running;

	enum WALK_SIDE { UP, DOWN, LEFT, RIGHT };
	WALK_SIDE currentWalkSide;

	void clearPlayer();
	void loadPlayerTexture(std::string filePath);
	void handlePlayerKeyDownEvent(SDL_Event ev, int frame);
	void handlePlayerKeyUpEvent(SDL_Event ev);
	void updatePlayerTexture(int frame);
	void changeWalkDirection(WALK_SIDE walkSide, int playerTextureY);

	void startRunning();
	void stopRunning();

	void moveUp(int frame);
	void moveDown(int frame);
	void moveLeft(int frame);
	void moveRight(int frame);

	int textureWidth;
	int textureHeight;
	int frameWidth;
	int	frameHeight;
	int motionUsed = 1;
};