#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>

using namespace std;

class Scene
{
public:
	Scene(string name, string mapPath);
	~Scene();
	void Load();

private:
	string name;
	int width;
	int height;
	vector<vector<int>> mapbg;
	SDL_Texture *tileset; 
	//SDL_Surface *fgLayer;
};

#endif