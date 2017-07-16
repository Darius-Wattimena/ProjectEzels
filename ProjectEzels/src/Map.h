#pragma once

#include "Game.h"

class Map {
public:
	SDL_Texture* mapTexture;

	Map::Map(Game* game);
	void loadMapTexture(std::string filePath);

	int mapWidth;
	int mapHeight;
};

