#pragma once

#include <SDL/SDL_stdinc.h>

class TimeManager {

private:
	Uint32 m_gameTime = 0;
	double m_deltaTime = 0;
	Uint16 m_fps = 60;
	double m_fpsReal = 60;

	double m_msPerFrame = 1000. / static_cast<double>(m_fps);
	Uint32 m_delayTime = 0;


public:
	Uint32 getGameTime() const;
	double getDeltaTime() const;
	Uint32 getFPS() const;
	double getFPSreal() const;

	void  setFPS(const Uint16& newFPS);
	void  resetDelay();

	void  calcGameAndDeltaTime();
	void  delay();


};

