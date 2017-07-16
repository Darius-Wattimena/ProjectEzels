#pragma once

#include "MainWindow.h"

class Game {
public:
	Game::Game(MainWindow mainWindow);
	void handleEvent(SDL_Event sdlEvent);
};
