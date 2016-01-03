#pragma once

typedef const char cchar;
typedef unsigned int uint;







struct WindowFlags {
	static const int fullscreen;
	static const int opengl;
	static const int shown;
	static const int hidden;
	static const int borderless;
	static const int resizable;
	static const int minimized;
	static const int maximized;
	static const int inputGrabbed;
	static const int inputFocus;
	static const int mouseFocus;
	static const int fullscreenDesktop;
	static const int foreign;
	static const int allowHighDPI;
	static const int mouseCapture;
};





struct Window
{ 
	static bool create(cchar* title = "Game", int xPos = 100, int yPos = 100, int width = 951, int height = 540, uint flag =  WindowFlags::shown);
	static bool setFullscreen(uint flag = WindowFlags::fullscreenDesktop);
	static void destroy();
};


