#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <Mouse.hpp>
#include <Keyboard.hpp>

enum EEvent
{
	e_event_no_event,
	e_event_mouse_pressed,
	e_event_mouse_released,
	e_event_mouse_moved,
	e_event_mouse_scrolled,
	e_event_key_pressed,
	e_event_key_released,
	e_event_resize,
	e_event_close,

	e_event_count // keep at the end of the enum
};

typedef struct NoEvent
{
	EEvent type;
} NoEvent;

typedef struct MouseEvent
{
	EEvent type;
	int x;
	int y;
	EMouseButton button;
	int delta;
};

typedef struct KeyboardEvent
{
	EEvent type;
	Key key;
};

typedef struct ResizeEvent
{
	EEvent type;
	unsigned int width;
	unsigned int height;
} ResizeEvent;

union Event
{
	EEvent type;
	NoEvent noEvent;
	MouseEvent mouse;
	KeyboardEvent keyboard;
	ResizeEvent resize;
};

#endif // __EVENT_HPP
