#include "../include/TimeManager.h"
#include <SDL/SDL_timer.h>



Uint32 TimeManager::getGameTime() const {
	return m_gameTime;
}
double TimeManager::getDeltaTime() const {
	return m_deltaTime;
}
Uint32 TimeManager::getFPS() const {
	return m_fps;
}
double TimeManager::getFPSreal() const {
	return m_fpsReal;
}


void    TimeManager::setFPS(const Uint16& newFPS) {

	m_fps = newFPS;
	m_msPerFrame = 1000. / static_cast<double>(m_fps);
}

void    TimeManager::resetDelay() {

	m_delayTime = m_gameTime;
}


void    TimeManager::calcGameAndDeltaTime() {

	Uint32 lastGameTime = m_gameTime;
	m_gameTime = SDL_GetTicks();

	Uint32 diff = static_cast<double>(m_gameTime - lastGameTime);
	m_deltaTime = .001 * diff;
	m_fpsReal = 1000. / diff;
}

void    TimeManager::delay() {

	Uint32 lastDelayTime = m_delayTime;
	m_delayTime = SDL_GetTicks();

	double diff = static_cast<double>(m_delayTime - lastDelayTime);

	if (diff < m_msPerFrame)
		SDL_Delay( static_cast<Uint32>(m_msPerFrame - diff) );

	m_delayTime = SDL_GetTicks();
}

