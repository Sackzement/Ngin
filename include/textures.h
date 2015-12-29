#pragma once

/*
texture.loadTexture("house.png");
texture.unloadAllTextures();
texture.list
*/



struct CTextures;
extern CTextures textures;




#include <map>
using std::map;


struct Texture {
	const void*  texturePtr;
	const int    width;
	const int    height;
	const char*  name;

	Texture(void* texturePtr, int width, int height, const char* name);
};

struct CTextures {

private:
	map<const char*, const Texture> m_list;
public:
	const map<const char*, const Texture>& list = m_list ;
	bool loadTexture(const char * fileName);
	void unloadAllTextures();

};



