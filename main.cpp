#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "game.h"
#include "scene.h"

using namespace std;

void game_loop()
{
	bool quit = false;
	Scene newscene("Test", "../Resources/maps/map.txt");

	// Enter the main game loop
	while (!quit)
	{
		Game::HandleInput(&quit);

		Game::Player->HandleInput();
		Game::Player->Move();

		Game::Time->reset();
		SDL_RenderClear(Game::Renderer);
		newscene.Load();
		Game::Player->draw(); 

		SDL_RenderPresent(Game::Renderer);
	}
}

int main(int argc, char *argv[])
{
	if (!Game::Init())
	{
		cout << "Error initializing: " <<  SDL_GetError() << endl;
		return -1;
	}
	Game::InitMap();
	 cout << "";
	
	//delete newscene;
	game_loop();

	Game::Quit();

	return 0;
}