#include <iostream>
#include <string>
#include "SDL.h"
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
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void MainWindow::createWindow()
{
	window = SDL_CreateWindow("Project Ezel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		throw CustomException(_CRT_WIDE(__FILE__), __LINE__, L"Error creating the window");
	}

	windowSurface = SDL_GetWindowSurface(window);
}

void MainWindow::createRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == NULL) {
		throw CustomException(_CRT_WIDE(__FILE__), __LINE__, L"Error creating the renderer");
	}
}
