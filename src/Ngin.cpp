
#include "../include/Ngin.h"
#include "../include/Object.h"
#include <iostream>


Ngin ngin;



Ngin:: Ngin() :

m_gameTime (0),
m_deltaTime (0.),
m_fps (60),
m_msPerFrame (1000./(double)m_fps),
m_delayTime (0),

m_quit (false),
m_window (NULL),
m_renderer (NULL),
       
m_fonts (),

m_scripts (),



m_objects ()
{}


bool    Ngin:: initLibs()       {
    
        // INIT SDL
        if    ( SDL_Init(SDL_INIT_EVERYTHING) != 0 )  {
            
            printf( "Error:  Failed to init SDL  %s\n", SDL_GetError() );
            return false;
        }
        
        // INIT SDL_img
        if( IMG_Init(IMG_INIT_PNG) == 0 )  {
            
            printf( "Error:  Failed to init SDL_img  %s\n", SDL_GetError() );
			return false;
        }

		// INIT SDL_ttf
        if   ( TTF_Init() == -1 )  {
            
            printf( "Error:  Failed to init SDL_ttf  %s\n", SDL_GetError() );
			return false;
        }
        
		return true;
    }
bool    Ngin:: createWindowAndRenderer(const char* title, int x, int y, int w, int h, Uint32 winFlags, Uint32 renFlags)
{
	if (m_window)
	{
		std::cout << "Error:  Window already created" << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow(title, x, y, w, h, winFlags);
	if (!m_window)
	{
		printf("Error:  Failed to create window  %s\n", SDL_GetError());
		return false;
	}

	m_renderer = SDL_GetRenderer(m_window);
	if (!m_renderer)
	{
		m_renderer = SDL_CreateRenderer(m_window, -1, renFlags);
		if (!m_renderer)
		{
			printf("Error:  Failed to create renderer  %s\n", SDL_GetError());
			return false;
		}
	}

	return true;
}
void    Ngin:: enterMainLoop()  {
    
    doCapGtimeCalcDt();
    m_delayTime = m_gameTime;
    
    while ( !m_quit ) {
        doCapGtimeCalcDt();
        doScripts();
        doInput();
        doUpdate();
		doCollision();
        doDelay();
        doRender();
    }
}

void    Ngin:: quit()
{
	m_quit = true;
}
void    Ngin:: setFPS(const Uint16& newFPS)  {
    
    m_fps = newFPS;
    m_msPerFrame = 1000. / double(m_fps);
}

void    Ngin:: free()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

}

SDL_Renderer* Ngin:: getRenderer()
{
	return m_renderer;
}
SDL_Window*  Ngin::  getWindow()
{
	return m_window;
}

bool Ngin:: isKeyDown(SDL_Scancode key)
{
	if (m_keyStates[key] == true)
		return true;
	else
		return false;
}
bool Ngin:: isKeyDownOnce(SDL_Scancode key)
{
	return m_keyStatesOnceDown[key];
}
bool Ngin:: isKeyUpOnce(SDL_Scancode key)
{
	return m_keyStatesOnceUp[key];
}

void Ngin::addObject(Object& obj)
{
	addScript( [this,obj] () { this->m_objects.push_back(obj); } );
}
void Ngin::addScript(std::function<void()> func)
{
	m_scripts.push_back(func);
}

void    Ngin:: doCapGtimeCalcDt() {
    
    Uint32 lastGameTime = m_gameTime;
    m_gameTime = SDL_GetTicks();
    
    m_deltaTime = .001 * static_cast<double>(m_gameTime - lastGameTime);
}
void    Ngin:: doScripts()      {
        
        for (auto it = m_scripts.begin(); it != m_scripts.end(); ++it)
            (*it)();
        
		m_scripts.clear();
    }
void    Ngin:: doInput()        {

	memset(m_keyStatesOnceDown, false, SDL_NUM_SCANCODES);
	memset(m_keyStatesOnceUp, false, SDL_NUM_SCANCODES);
        
    for (SDL_Event ev; SDL_PollEvent(&ev) != 0 ;)
        switch (ev.type)  {
                    
            case SDL_QUIT:
				m_quit = true;
                break;
                    
            case SDL_KEYDOWN:
				if (ev.key.repeat == 0)
				{
					m_keyStatesOnceDown[ev.key.keysym.scancode] = 1;
					m_keyStates[ev.key.keysym.scancode] = 1;
				}
                break;
                    
            case SDL_KEYUP:
				m_keyStatesOnceUp [ev.key.keysym.scancode]  = 1;
				m_keyStates[ev.key.keysym.scancode] = 0;
                break;
        }
        
    for (auto it = m_objects.begin(); it != m_objects.end(); ++it)  {
            
        (*it).input();
    }
}
void    Ngin:: doUpdate()       {
        
        for (auto it = m_objects.begin(); it != m_objects.end(); ++it)  {
            
            (*it).update();
        }
}
void    Ngin:: doCollision()      {
    
	for (auto it = m_collChecks.begin(); it != m_collChecks.end(); ++it) {
		(*it)();
	}
}
void    Ngin:: doDelay()        {
    
    Uint32 oldDelayTime = m_delayTime;
    m_delayTime = SDL_GetTicks();
    
    Uint32 diff = m_delayTime - oldDelayTime;
    
    if ( double(diff) < m_msPerFrame )  {
        
		Uint32 toWait = Uint32( m_msPerFrame - double(diff) );
        SDL_Delay(toWait);
    }
    
    m_delayTime = SDL_GetTicks();
}
void    Ngin:: doRender()       {
        
        SDL_SetRenderDrawColor(m_renderer, 0,0,0,255);
        SDL_RenderClear(m_renderer);
        
        for (auto it = m_objects.begin(); it != m_objects.end(); ++it)  {
            
            //(*it).render(ren);
        }
        
        SDL_RenderPresent(m_renderer);
    }
    
    
    

    





