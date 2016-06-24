#include <iostream>

#include "player.h"
#include "game.h"

using namespace std;

PlayerCharacter::PlayerCharacter(string name, SDL_Rect rect, SDL_Surface *img) : GameObject(name, rect, img)
{
	//TODO:
}

void PlayerCharacter::HandleInput()
{
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	xVelocity = 0;
	yVelocity = 0;

	if (keyState[SDL_SCANCODE_W]) // If the player presses the space key
    {
        if (keyState[SDL_SCANCODE_D])
	    {
	    	yVelocity = -PLAYER_SPEED/1.5f;
			xVelocity = PLAYER_SPEED/1.5f;
	    }
	    else if (keyState[SDL_SCANCODE_A])
	    {
	    	yVelocity = -PLAYER_SPEED/1.5f;
	    	xVelocity = -PLAYER_SPEED/1.5f;
	    }
	    else
	    {
	    	xVelocity = 0;
	    	yVelocity = -PLAYER_SPEED;
	    }
    }
    else if (keyState[SDL_SCANCODE_S])
    {
    	 if (keyState[SDL_SCANCODE_D])
	    {
	    	yVelocity = PLAYER_SPEED/1.5f;
			xVelocity = PLAYER_SPEED/1.5f;
	    }
	    else if (keyState[SDL_SCANCODE_A])
	    {
	    	yVelocity = PLAYER_SPEED/1.5f;
	    	xVelocity = -PLAYER_SPEED/1.5f;
	    }
	    else
	    {
	    	xVelocity = 0;
	    	yVelocity = PLAYER_SPEED;
	    }
    }
	else if (keyState[SDL_SCANCODE_D])
    {
    	xVelocity = PLAYER_SPEED;
    }

    else if (keyState[SDL_SCANCODE_A])
    {
    	xVelocity = -PLAYER_SPEED;
    }
}

void PlayerCharacter::Move()
{
	xpos += xVelocity*Game::Time->deltaTime()/1000.0f;
	ypos += yVelocity*Game::Time->deltaTime()/1000.0f;
}