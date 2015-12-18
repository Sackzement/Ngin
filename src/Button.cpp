#include "../include/Button.h"


Button:: Button( void(*pressFunc)() ) :
	Object(),
	state(btn_state::none) ,
	m_pressFunc(pressFunc)
{}
void Button::press()
{
	if (m_pressFunc)
		m_pressFunc();
}
void Button::setPressFunc(void(*pressFunc)())
{
		m_pressFunc = pressFunc;
}