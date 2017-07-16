#pragma once

#include "SDL.h"

class MainWindow {
public:
	SDL_Window *window = nullptr;
	SDL_Surface *windowSurface = nullptr;
	SDL_Renderer *renderer = nullptr;
	MainWindow::MainWindow();
	bool isRunning();
	void stopRunning();
	void close();
private:
	bool running = false;
	void createWindow();
	void createRenderer();
};