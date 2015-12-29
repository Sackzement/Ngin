#pragma once

typedef const char cchar;
typedef unsigned int uint;





struct CWindow;
extern CWindow window;



struct CWindowFlags {
	const int fullscreen;
    const int opengl;
	const int shown;
	const int hidden;
	const int borderless;
	const int resizable;
	const int minimized;
	const int maximized;
	const int inputGrabbed;
	const int inputFocus;
	const int mouseFocus;
	const int fullscreenDesktop;
	const int foreign;
	const int allowHighDPI;
	const int mouseCapture;

	CWindowFlags();
};





struct CWindow
{ 
	const  CWindowFlags flags;
	bool create(cchar* title = "Game", int xPos = 100, int yPos = 100, int width = 951, int height = 540, uint flag =  window.flags.shown);
	bool setFullscreen(uint flag = window.flags.fullscreenDesktop);
	void destroy();
};


