#pragma once
#include "Object.h"

class Button : public Object
{
public:
	static enum btn_state
	{
		none,
		highlighted,
		pressed
	};

	btn_state  state;

	Button( void(*pressFunc)() );
	void press();
	void setPressFunc( void(*pressFunc)() );

private:
	void(*m_pressFunc)();

};




