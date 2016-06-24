#include <iostream>

#include "game.h"

using namespace std;

SDL_Window *Game::MainWindow = NULL;
SDL_Renderer *Game::Renderer = NULL;
PlayerCharacter *Game::Player = NULL;
map<int, Tile> Game::Tiledb;
Timer *Game::Time = NULL; 

Timer::Timer()
{
    startTime = SDL_GetTicks();
}

// Updating the time
float Timer::deltaTime()
{
    return SDL_GetTicks() - startTime;
}

void Timer::reset()
{
    startTime = SDL_GetTicks();
}

bool Game::Init()
{
	// Initializing SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Error initializing SDL: " << SDL_GetError();
		return false;
	}

	// Initializing pngs
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		cout << "Error initializing SDL_image: " << IMG_GetError();
		return false;
	}

	MainWindow = SDL_CreateWindow("Goodknight", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
								SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (MainWindow == NULL)
	{
		cout << "Error creating window: " << SDL_GetError();
		return false;
	}

	Renderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
	if (Renderer == NULL)
	{
		cout << "Error creating Renderer: " << SDL_GetError();
		return false;
	}

	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 32;
	r.h = 32;

	Game::Player = new PlayerCharacter("Ryan", r, IMG_Load("../Resources/sprites/altplayer.png"));
	Game::Time = new Timer();

	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);		
	SDL_UpdateWindowSurface(MainWindow);
	return true;
}

void Game::InitMap()
{
	//Tile grass("grass", "../Resources/grass.png");
	//Tiledb.emplace(200, grass);
}

void Game::HandleInput(bool *quit)
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			*quit = true;
	}
}

void Game::Quit()
{
	delete Player;
	delete Time;

	SDL_DestroyWindow(MainWindow);
	SDL_DestroyRenderer(Renderer);
	IMG_Quit();
	SDL_Quit();
}