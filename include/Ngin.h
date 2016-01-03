#pragma once
#include <vector>
#include <functional>
#include <string>
#include <map>
#include <SDL/SDL.h>
#include <SDL/SDL_video.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
class Object;

typedef void (*vfuncv) ();

#include "Button.h"



class Ngin {
private:
    
    Uint32 m_gameTime;
    double m_deltaTime;
    Uint16 m_fps;
    double m_msPerFrame;
    Uint32 m_delayTime;
    
    bool           m_quit;
    SDL_Window*    m_window;
	SDL_Renderer*  m_renderer;
    
    std::map<std::string,TTF_Font*>  m_fonts;
    
    std::vector<std::function<void()>>                m_scripts;
    
	bool m_keyStates[SDL_NUM_SCANCODES];
	bool m_keyStatesOnceDown[SDL_NUM_SCANCODES];
	bool m_keyStatesOnceUp[SDL_NUM_SCANCODES];

	
    
    
    std::vector<Object>         m_objects;

	std::vector<vfuncv>                m_collChecks;
    
    // FUNCTIONS-----------------------------------

public: 
	struct
	{ 
		SDL_Scancode up = SDL_SCANCODE_UP;
		SDL_Scancode down = SDL_SCANCODE_DOWN;
		SDL_Scancode left = SDL_SCANCODE_LEFT;
		SDL_Scancode right = SDL_SCANCODE_RIGHT;
		SDL_Scancode select = SDL_SCANCODE_RETURN;
		SDL_Scancode back = SDL_SCANCODE_ESCAPE;

	}controls;

          Ngin();
    
    bool  initLibs();
	bool  createWindowAndRenderer(const char* title, int x, int y, int w, int h, Uint32 winFlags, Uint32 renFlags);
    void  enterMainLoop();

	void  quit();
    void  setFPS(const Uint16& newFPS);

	void free();
	
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

	bool isKeyDown(SDL_Scancode key);
	bool isKeyDownOnce(SDL_Scancode key);
	bool isKeyUpOnce(SDL_Scancode key);

	void addObject(Object& obj);
	void addScript(std::function<void()> func);

private:
    void  doCapGtimeCalcDt();
    void  doScripts();
    void  doInput();
    void  doUpdate();
	void  doCollision();
    void  doDelay();
    void  doRender();
};




extern Ngin ngin;




