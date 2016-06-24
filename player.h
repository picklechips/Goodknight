#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "gameobject.h"

using namespace std;

class PlayerCharacter : public GameObject
{
public:
	PlayerCharacter(string name, SDL_Rect rect, SDL_Surface *img);
	void HandleInput();
	void Move ();

	int yVel(){return yVelocity;}
	int xVel(){return xVelocity;}
	void setVely(int vel){yVelocity = vel;}
	void setVelx(int vel){xVelocity = vel;}
private:
	int yVelocity, xVelocity;
};

#endif