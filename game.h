#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>
#include <memory>

#include "player.h"
#include "gameobject.h"
#include "tile.h"

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 512;

const int PLAYER_SPEED = 160;

using namespace std;

// Timer class
class Timer
{
private:
    float startTime; // The time when the timer started running

public:
    Timer();
    void reset();
    float deltaTime();
};

class Game
{
public:
	static SDL_Window *MainWindow;
	static SDL_Renderer *Renderer;
	static PlayerCharacter *Player;
	static Timer *Time;
	static map<int, Tile> Tiledb;
	static bool Init();
	static void Quit();
	static void HandleInput(bool *quit);
	static void InitMap();
};

#endif 