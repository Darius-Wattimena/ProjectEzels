#pragma once

#include "MainWindow.h"
#include "CustomException.h"
#include <iostream>

class Game {
public:
	Game::Game(MainWindow mainWindow);
	SDL_Surface *loadSurface(std::string filePath);
	SDL_Texture *loadTexture(std::string filePath);
	void handleEvent();
	void handleKeyEvent();
	void resetFrame();
};
