#include <iostream>

#include "game.h"

using namespace std;

GameObject::GameObject(string objname, SDL_Rect rect, SDL_Surface *img) : name(objname)
{
	if (img == NULL)
		cout << "GameObject " << name << ": Error loading image - " << IMG_GetError() << endl;
	else
		image = SDL_CreateTextureFromSurface(Game::Renderer, img);

	if (image == NULL)
		cout << "GameObject " << name << ": Error creating texture - " << SDL_GetError() << endl;

	xpos = rect.x;
	ypos = rect.y;
	width = rect.w;
	height = rect.h;
	SDL_FreeSurface(img);
}

GameObject::GameObject(string objname, float x, float y, int w, int h, SDL_Surface *img) : name(objname),
	xpos(x), ypos(y), width(w), height(h)
{
	if (img == NULL)
		cout << "GameObject " << name << ": Error loading image - " << IMG_GetError() << endl;
	else
		image = SDL_CreateTextureFromSurface(Game::Renderer, img);

	if (image == NULL)
		cout << "GameObject " << name << ": Error creating texture - " << SDL_GetError() << endl;

	SDL_FreeSurface(img);
}

void GameObject::setPos(float x, float y)
{
	xpos = x;
	ypos = y;
}

void GameObject::draw()
{
	SDL_Rect pos;
	pos.x = xpos;
	pos.y = ypos;
	pos.w = width;
	pos.h = height;
	SDL_RenderCopy(Game::Renderer, image, NULL, &pos);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(image);
	image = NULL;
}