#pragma once
#include <vector>
#include <string>
#include <map>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "Object.h"

typedef void (*func) ();





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
    
    std::vector<func>                m_scripts;
    
    std::map<SDL_Keycode, bool>      m_kbState;
    std::map<SDL_Keycode, bool>      m_kbStateOnceDown;
    std::map<SDL_Keycode, bool>      m_kbStateOnceUp;
    
    
    std::vector<Object*>         m_objects;

	std::vector<func>                m_collChecks;
    
    // FUNCTIONS-----------------------------------

public:
          Ngin();
    
    bool  initLibs();
    void  enterMainLoop();

	void  quit();
    void  setFPS(const Uint16& newFPS);
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
    
private:
    void  doCapGtimeCalcDt();
    void  doScripts();
    void  doInput();
    void  doUpdate();
	void  doCollision();
    void  doDelay();
    void  doRender();
};





extern Ngin engine;




