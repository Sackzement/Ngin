#pragma once







struct RendererFlags {

	static const int software;
	static const int accel;
	static const int vsync;
	static const int texture;
};



struct Renderer {

	static bool create(int index = -1, int flag = RendererFlags::accel);
	static void destroy();
};


