#include <iostream>
#include "SDL.h"
#include "MainWindow.h"
#include "Game.h"

int main(int argc, char *args[]) {

	bool running;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Initialization Error : " << SDL_GetError() << std::endl;
	} 
	else {
		MainWindow mainWindow = MainWindow();
		Game game = Game(mainWindow);
	}

	return 0;
}