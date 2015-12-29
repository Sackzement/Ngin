#pragma once




struct CRenderer;
extern CRenderer renderer;




struct CRendererFlags {

	const int software;
	const int accel;
	const int vsync;
	const int texture;

	CRendererFlags();
};



struct CRenderer {

	CRendererFlags flags;
	bool create(int index = -1, int flag = renderer.flags.accel);
	void destroy();
};


