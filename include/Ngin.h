#pragma once
#include <vector>
#include <string>
#include <map>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
class Object;

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
	bool  createWindowAndRenderer(const char* title, int x, int y, int w, int h, Uint32 winFlags, Uint32 renFlags);
    void  enterMainLoop();

	void  quit();
    void  setFPS(const Uint16& newFPS);
	
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

	bool isKeyDown(SDL_Keycode key);
	bool isKeyDownOnce(SDL_Keycode key);
	bool isKeyUpOnce(SDL_Keycode key);

	void addObject(Object* obj);
    
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




