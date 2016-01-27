#pragma once

#include <SDL/SDL_stdinc.h>

struct Time {
private:
	Uint32 m_gameTime = 0;
	double m_deltaTime = 0;
	Uint16 m_fps = 60;
	double m_fpsReal = 60;
public:
	const Uint32 & total;
	const Uint32 & delta;
	const Uint32 & fps;
	const Uint32 & fps_real;


private:

	double m_msPerFrame;
	Uint32 m_delayTime;


public:
    
    Time();
	void  setFPS(const Uint16& newFPS);
	void  resetDelay();

	void  update();
	void  delay();


};

