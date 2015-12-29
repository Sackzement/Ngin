/*
texture.loadTexture("house.png");
texture.unloadAllTextures();
texture.list


*/



#pragma once
#include <map>
using std::map;

typedef unsigned int uint;
typedef const char cchar;

struct Texture {
	const void* texturePtr= nullptr;
	cchar* name = "";
	uint width = 0;
	uint height = 0;
};

struct Ctextures {


	static map<cchar*, Texture> list;
	bool loadTexture(cchar * fileName);
	static void unloadAllTextures();

};




	static Ctextures textures;