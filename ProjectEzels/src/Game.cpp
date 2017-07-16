#include "SDL.h"
#include "Game.h"
#include "MainWindow.h"

SDL_Event ev;
MainWindow gmw;

Game::Game(MainWindow mainWindow)
{
	gmw = mainWindow;

	while (gmw.isRunning()) {

		while (SDL_PollEvent(&ev) != 0) {
			handleEvent(ev);
		}

	}
}

void Game::handleEvent(SDL_Event sdlEvent)
{
	if (ev.type == SDL_QUIT) {
		gmw.stopRunning();
		gmw.close();
	}
}
