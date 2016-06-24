#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

class Tile
{
public:
	Tile(string tileName, string imgpath, string colliderpath = "");
	~Tile();
	SDL_Texture *Texture(){return texture;}
	SDL_Surface *Collider(){return collider;}
	string Name(){return name;}
	int width(){return w;}
	int height(){return h;}
	bool hasCollision(){return collision;}

private:
	SDL_Texture *texture;
	SDL_Surface *collider;
	int w, h;
	bool collision;
	string name;
};

#endif