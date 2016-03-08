#include <Keyboard.hpp>

#include <GL/glut.h>

#if defined(__WIN32__)
#include <Windows.h>
#else
	// Not implemented yet
#endif

/*static*/ bool Keyboard::s_keys[e_key_count];
/*static*/ int Keyboard::s_modifiers = 0;
/*static*/ int Keyboard::s_oldModifiers = 0;

/*explicit*/ Key::Key()
	: code(e_key_NULL)
	, character(0)
{

}

/*explicit*/ Key::Key(EKeyCode co, unsigned char ch)
	: code(co)
	, character(ch)
{

}

/*virtual*/ Keyboard::~Keyboard() {}

/*static*/ void Keyboard::Initialize()
{
	for(register unsigned int i = 0; i < e_key_count; ++i)
	{
		s_keys[i] = false;
	}
	s_modifiers = 0;
	s_oldModifiers = 0;
}

/*static*/ void Keyboard::UpdateModifiers()
{
	s_oldModifiers = s_modifiers;
	//s_modifiers = glutGetModifiers();
#if defined(__WIN32__)
	s_modifiers = 0;
	if(0 != GetAsyncKeyState(VK_LSHIFT))
	{
		SetKey(e_key_left_shift, true);
		s_modifiers |= GLUT_ACTIVE_SHIFT;
	}
	if(0 != GetAsyncKeyState(VK_RSHIFT))
	{
		SetKey(e_key_right_shift, true);
		s_modifiers |= GLUT_ACTIVE_SHIFT;
	}
	if(0 != GetAsyncKeyState(VK_LCONTROL))
	{
		SetKey(e_key_left_ctrl, true);
		s_modifiers |= GLUT_ACTIVE_CTRL;
	}
	if(0 != GetAsyncKeyState(VK_RCONTROL))
	{
		SetKey(e_key_right_ctrl, true);
		s_modifiers |= GLUT_ACTIVE_CTRL;
	}
	if(0 != GetAsyncKeyState(VK_LMENU))
	{
		SetKey(e_key_left_alt, true);
		s_modifiers |= GLUT_ACTIVE_ALT;
	}
	if(0 != GetAsyncKeyState(VK_RMENU))
	{
		SetKey(e_key_right_alt, true);
		s_modifiers |= GLUT_ACTIVE_ALT;
	}
	SetKey(e_key_shift, IsShiftPressed());
	SetKey(e_key_ctrl, IsCtrlPressed());
	SetKey(e_key_alt, IsAltPressed());
#else
	// Not implemented yet
#endif
}

/*static*/ bool Keyboard::IsShiftPressed()
{
	return 0 != (s_modifiers & GLUT_ACTIVE_SHIFT);
}

/*static*/ bool Keyboard::IsCtrlPressed()
{
	return 0 != (s_modifiers & GLUT_ACTIVE_CTRL);
}

/*static*/ bool Keyboard::IsAltPressed()
{
	return 0 != (s_modifiers & GLUT_ACTIVE_ALT);
}

/*static*/ bool Keyboard::IsShiftStateChanged()
{
	return 0 != ((s_modifiers ^ s_oldModifiers) & GLUT_ACTIVE_SHIFT);
}

/*static*/ bool Keyboard::IsCtrlStateChanged()
{
	return 0 != ((s_modifiers ^ s_oldModifiers) & GLUT_ACTIVE_CTRL);
}

/*static*/ bool Keyboard::IsAltStateChanged()
{
	return 0 != ((s_modifiers ^ s_oldModifiers) & GLUT_ACTIVE_ALT);
}

/*static*/ void Keyboard::SetKeyRepeatEnabled(bool state)
{
	if(state)
	{
		glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
	}
	else
	{
		glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	}
}

/*static*/ void Keyboard::SetKey(EKeyCode key, bool state)
{
	if(e_key_count != key)
	{
		s_keys[key] = state;
	}
}

/*static*/ bool Keyboard::GetKey(EKeyCode key)
{
	if(e_key_count == key)
	{
		return false;
	}
	return s_keys[key];
}

/*explicit*/ Keyboard::Keyboard() {}
