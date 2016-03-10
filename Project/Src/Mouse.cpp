#include <Mouse.hpp>

/*static*/ int Mouse::s_positionX;
/*static*/ int Mouse::s_positionY;
/*static*/ bool Mouse::s_buttonState[e_mouse_button_count];

/*virtual*/ Mouse::~Mouse() { }

/*static*/ void Mouse::Initialize()
{
	s_positionX = 0;
	s_positionY = 0;
	for(register unsigned int i = 0; i < e_mouse_button_count; ++i)
	{
		s_buttonState[i] = false;
	}
}

/*static*/ void Mouse::UpdateWheel()
{
	// Not yet implemented
}

/*static*/ int Mouse::GetPositionX()
{
	return s_positionX;
}

/*static*/ void Mouse::SetPositionX(int x)
{
	s_positionX = x;
}

/*static*/ int Mouse::GetPositionY()
{
	return s_positionY;
}

/*static*/ void Mouse::SetPositionY(int y)
{
	s_positionY = y;
}

/*static*/ bool Mouse::GetButton(EMouseButton button)
{
	if(e_mouse_button_count == button)
	{
		return false;
	}
	return s_buttonState[button];
}

/*static*/ void Mouse::SetButton(EMouseButton button, bool state)
{
	if(e_mouse_button_count != button)
	{
		s_buttonState[button] = state;
	}
}

/*explicit*/ Mouse::Mouse() { }
