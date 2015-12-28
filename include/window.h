#pragma once

typedef const char cchar;
typedef unsigned int uint;



struct CwindowFlags
{
	CwindowFlags();
	const uint fullscreen;
	const uint opengl;
	const uint shown;
	const uint hidden;
	const uint fullscreenDesktop;
	const uint allowHightDPI;
};


struct CWindow;
extern CWindow window;

struct CWindow
{
	const CwindowFlags flags;
	bool create(cchar* title = "Game", int xPos = 100, int yPos = 100, int width = 951, int height = 540, uint flag = window.flags.shown);
	bool setFullscreen(uint flag = window.flags.fullscreenDesktop);
	void destroy();
};
