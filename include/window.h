#pragma once

typedef const char cchar;
typedef unsigned int uint;



struct CwindowFlags
{
	const uint fullscreen = 1;
    const uint opengl     = 2;
	const uint shown      = 4;
	const uint hidden     = 8;
	const uint fullscreenDesktop = 4097;
	const uint allowHightDPI     = 8192;
};




struct CWindow;

extern CWindow window;

struct CWindow
{ 
	const  CwindowFlags flags;
	bool create(cchar* title = "Game", int xPos = 100, int yPos = 100, int width = 951, int height = 540, uint flag =  window.flags.shown);
	bool setFullscreen(uint flag = window.flags.fullscreenDesktop);
	void destroy();
};


