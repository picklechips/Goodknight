#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

class GameObject
{
protected:
	float xpos;
	float ypos;
	int width; 
	int height;

	SDL_Texture *image;
	string name;

public:
	GameObject(string objname, SDL_Rect dst, SDL_Surface *img = NULL);
	GameObject(string objname, float x, float y, int w, int h, SDL_Surface *img = NULL);
	void setPos(float x, float y);
	void setName(string objname) {name = objname;};
	const string Name(){return name;}
	virtual void draw();
	~GameObject();
};

#endif