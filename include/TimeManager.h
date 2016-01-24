#pragma once

#include <SDL/SDL_stdinc.h>

struct Time {
private:
	Uint32 m_gameTime = 0;
	double m_deltaTime = 0;
	Uint16 m_fps = 60;
	double m_fpsReal = 60;
public:
	const Uint32 & total = m_gameTime;
	const Uint32 & delta = m_deltaTime;
	const Uint32 & fps = m_fps;
	const Uint32 & fps_real = m_fpsReal;


private:

	double m_msPerFrame = 1000. / static_cast<double>(m_fps);
	Uint32 m_delayTime = 0;


public:

	void  setFPS(const Uint16& newFPS);
	void  resetDelay();

	void  update();
	void  delay();


};

