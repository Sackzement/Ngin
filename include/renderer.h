#pragma once

typedef const char cchar;
typedef unsigned int uint;

struct CrendererFlags {
	CrendererFlags();
	const uint software;
	const uint accel;
	const uint vsync;
	const uint texture;
};


struct CRenderer;
extern CRenderer renderer;

struct CRenderer
{
	CrendererFlags flags;
	bool create(int index = -1, uint flag = renderer.flags.accel | renderer.flags.accel);
	void destroy();
};


