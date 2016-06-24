#include <iostream>

#include "tile.h"
#include "game.h"

using namespace std;

Tile::Tile(string tileName, string imgpath, string colliderpath) : name(tileName)
{
	cout << colliderpath;
	 if (!colliderpath.empty())
	 {
	 	collider = IMG_Load(colliderpath.c_str());
		if (collider == NULL)
		{
			collision = false;
			cout << "Tile " << tileName << ": Error loading collider (" << IMG_GetError() << ")" << endl;
		}
		else
			collision = true;
	 }
	 else
	 	collider = NULL;

	SDL_Surface *tempsurface = IMG_Load(imgpath.c_str());
	if (tempsurface == NULL)
	{
		cout << "Tile " << tileName << ": Error loading texture (" << IMG_GetError() << ")" << endl;
	}
	else
	{
		w = tempsurface->w;
		h = tempsurface->h;
		cout << "Created tile " << tileName <<": " << w << "x" << h << endl;
		texture = SDL_CreateTextureFromSurface(Game::Renderer, tempsurface);
		SDL_FreeSurface(tempsurface);
	}
}

Tile::~Tile()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
	if (collider != NULL)
	{	
		SDL_FreeSurface(collider);
		collider = NULL;
	}
}
