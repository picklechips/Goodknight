#include <ostream>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "scene.h"
#include "game.h"

using namespace std;

Scene::Scene(string name, string mapPath) : name(name)
{
	tileset = NULL;
	string temp;
	vector<string> tempmap;
	ifstream mapfile(mapPath);
	if (mapfile.is_open())
	{
		while(getline(mapfile, temp))
		{
			tempmap.push_back(temp);
		}
		mapfile.close();
	}
	else
	{
		cout << "Unable to load map!" << endl;
		return;
	}
	
	vector<int> tempvector;
	for (int i = 0; i < tempmap.size(); i++)
	{
		istringstream sstream(tempmap[i]);
		while(getline(sstream, temp, ','))
		{
			int val;
			istringstream convert(temp);
			convert >> val;
			tempvector.push_back(val);
		}
		mapbg.push_back(tempvector);
		tempvector.clear();
	}
}

Uint32 get_pixel32( SDL_Surface *surface, int x, int y )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void Scene::Load()
{
	SDL_Surface *tilesettemp = IMG_Load("../Resources/tilesets/tileset.png");
	if (tilesettemp == NULL)
		cout << "fuck" << endl;
	SDL_Texture *tileset = SDL_CreateTextureFromSurface(Game::Renderer, tilesettemp);
	int width = tilesettemp->w / 32;
	int height = tilesettemp->h / 32;
	SDL_FreeSurface(tilesettemp);

	SDL_Rect dstrect;
	SDL_Rect srcrect;
	srcrect.w = 32;
	srcrect.h = 32;
	dstrect = srcrect;

	for (int y = 0; y < mapbg.size(); y++)
	{
		for (int x = 0; x < mapbg[y].size(); x++)
		{
			srcrect.x = ((mapbg[y][x]-1) %width)*32;
			srcrect.y = ((mapbg[y][x]-1)/width)*32;
			dstrect.x = x*32;
			dstrect.y = y*32;
			SDL_RenderCopy(Game::Renderer, tileset, &srcrect, &dstrect);
		}
	}
}

Scene::~Scene()
{
	if (tileset != NULL)
	{
		SDL_DestroyTexture(tileset);
		tileset = NULL;
	}
}