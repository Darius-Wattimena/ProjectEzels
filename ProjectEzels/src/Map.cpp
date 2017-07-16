#include "Map.h"

Game* mapGame;

Map::Map(Game* game)
{
	mapGame = game;
}

void Map::loadMapTexture(std::string filePath)
{
	mapTexture = mapGame->loadTexture(filePath);
	SDL_QueryTexture(mapTexture, NULL, NULL, &mapWidth, &mapHeight);
}
