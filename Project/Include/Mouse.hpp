#ifndef __MOUSE_HPP
#define __MOUSE_HPP

enum EMouseButton
{
	e_mouse_button_left,
	e_mouse_button_right,
	e_mouse_button_middle,

	e_mouse_button_count // keep at the end of the enum
};

class Mouse
{
public:

	virtual ~Mouse(void);

	static void Initialize(void);

	static void UpdateWheel(void);

	static int GetPositionX(void);
	static void SetPositionX(int x);

	static int GetPositionY(void);
	static void SetPositionY(int y);

	static bool GetButton(EMouseButton button);
	static void SetButton(EMouseButton button, bool state);

private:
	
	explicit Mouse(void);

	static int s_positionX;
	static int s_positionY;
	static bool s_buttonState[e_mouse_button_count];

};

#endif // __MOUSE_HPP