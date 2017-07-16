#include <iostream>
#include "Game.h"

#include "SDL_image.h"

int main(int argc, char *args[]) {

	bool running = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Initialization Error : " << SDL_GetError() << std::endl;
	} 
	else {

		if (IMG_Init(IMG_INIT_PNG) == 0) {
			std::cout << "Initialization Error : " << IMG_GetError() << std::endl;
		}
		else {
			MainWindow mainWindow = MainWindow();
			Game game = Game(mainWindow);
		}
	}

	return 0;
}