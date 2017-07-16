#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "MainWindow.h"
#include "CustomException.h"

using namespace std;

MainWindow::MainWindow()
{
	try {
		createWindow();
		createRenderer();

		running = true;
	}
	catch (const CustomException& e) {
		wcout << e.GetFullMessage() << SDL_GetError() << endl;
	}
}

bool MainWindow::isRunning()
{
	return running;
}

void MainWindow::stopRunning()
{
	running = false;
}

void MainWindow::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	renderer = nullptr;
	window = nullptr;

	SDL_Quit();
}

void MainWindow::createWindow()
{
	window = SDL_CreateWindow("Project Ezel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		throw CustomException(_CRT_WIDE(__FILE__), __LINE__, L"Error creating the window");
	}

	windowSurface = SDL_GetWindowSurface(window);
}

void MainWindow::createRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL) {
		throw CustomException(_CRT_WIDE(__FILE__), __LINE__, L"Error creating the renderer");
	}
}
