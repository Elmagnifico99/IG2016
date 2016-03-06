#include <Application.hpp>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Platform dependent timer
#if defined(__WIN32__)
#include <Windows.h>
#else
#include <X11/Xlib.h>
#endif

/*static*/ Application* Application::s_instance = nullptr;

/*explicit*/ Application::Parameters::Parameters()
		: WindowTitle("OpenGL Application")
		, Width(800)
		, Height(600)
		, CenterWindow(true)
		, PositionX(0)
		, PositionY(0)
		, EnableDepthBuffer(true)
		, EnableStencilBuffer(false)
		, DoubleBuffering(true)
		, IndexedColors(false)
		, EnableMultiSampling(false)
		, EnableStereo(false)
		, FullScreen(false)
		, FixedSize(false)
		, EnableOverlay(false)
{

}

/*virtual*/ void Application::ResizeWindow(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;
	glutReshapeWindow(width, height);
}

bool Application::Start(int argc, char** argv, const Parameters& parameters)
{
	if(nullptr != s_instance)
	{
		return false;
	}
	s_instance = this;
	glutInit(&argc,argv);
	int initFlags = 0;
	if(parameters.EnableDepthBuffer)
	{
		initFlags |= GLUT_DEPTH;
	}
	if(parameters.EnableStencilBuffer)
	{
		initFlags |= GLUT_STENCIL;
	}
	if(parameters.DoubleBuffering)
	{
		initFlags |= GLUT_DOUBLE;
	}
	else
	{
		initFlags |= GLUT_SINGLE;
	}
	if(parameters.IndexedColors)
	{
		initFlags |= GLUT_INDEX;
	}
	else
	{
		initFlags |= GLUT_RGB;
	}
	if(parameters.EnableMultiSampling)
	{
		initFlags |= GLUT_MULTISAMPLE;
	}
	if(parameters.EnableStereo)
	{
		initFlags |= GLUT_STEREO;
	}
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(parameters.Width, parameters.Height);
	if(parameters.CenterWindow)
	{
		int width = 0;
		int height = 0;
#if defined(__WIN32__)
		RECT rect;
		if(GetWindowRect(GetDesktopWindow(), &rect))
		{
			int width = rect.right - rect.left;
			int height = rect.bottom - rect.top;
		}
#else
		Display* d = XOpenDisplay(NULL);
		Screen*  s = DefaultScreenOfDisplay(d);
		width = s->width;
		height = s->height;
#endif
		glutInitWindowPosition((width - parameters.PositionX) / 2, (height - parameters.PositionY) / 2);
	}
	else
	{
		glutInitWindowPosition(parameters.PositionX, parameters.PositionY);
	}
	if(parameters.FullScreen)
	{
		glutFullScreen();
	}
	m_fixedSize = parameters.FixedSize;
	m_width = parameters.Width;
	m_height = parameters.Height;
	glutCreateWindow(parameters.WindowTitle.c_str());
	atexit(Application::__internal_RELEASE);

	OnInitialize(argc, argv);

	if(parameters.EnableOverlay)
	{
		glutOverlayDisplayFunc(Application::__internal_OVERLAY_DISPLAY_FUNC);
	}
	glutDisplayFunc(Application::__internal_DISPLAY_FUNC);
	glutReshapeFunc(Application::__internal_RESHAPE_FUNC);
	glutKeyboardFunc(Application::__internal_KEYBOARD_FUNC);
	glutKeyboardUpFunc(Application::__internal_KEYBOARD_UP_FUNC);
	glutMouseFunc(Application::__internal_MOUSE_FUNC);
	glutMotionFunc(Application::__internal_MOTION_FUNC);
	glutPassiveMotionFunc(Application::__internal_PASSIVE_MOTION_FUNC);
	glutVisibilityFunc(Application::__internal_VISIBILITY_FUNC);
	glutEntryFunc(Application::__internal_ENTRY_FUNC);
	glutSpecialFunc(Application::__internal_SPECIAL_FUNC);
	glutSpecialUpFunc(Application::__internal_SPECIAL_UP_FUNC);
	glutIdleFunc(Application::__internal_IDLE_FUNC);

	glutMainLoop();
	return true;
}

void Application::Close() const
{
	exit(0);
}

/*static*/ void Application::__internal_DISPLAY_FUNC()
{
	s_instance->OnUpdate(glutGet(GLUT_ELAPSED_TIME) / 1000.0f);
}

/*static*/ void Application::__internal_OVERLAY_DISPLAY_FUNC()
{
	// Nothing to do
}

/*static*/ void Application::__internal_RESHAPE_FUNC(int width, int height)
{
	if(s_instance->m_fixedSize)
	{
		s_instance->ResizeWindow(s_instance->m_width, s_instance->m_height);
	}
	else
	{
		s_instance->m_width = width;
		s_instance->m_height = height;
		s_instance->OnResizingWindow((unsigned int)width, (unsigned int)height);
	}
}

/*static*/ void Application::__internal_KEYBOARD_FUNC(unsigned char key, int x, int y)
{
	Keyboard::SetKey((EKeyCode)key, true);
	s_instance->OnKeyPressed(Key((EKeyCode)key, key));
}

/*static*/ void Application::__internal_KEYBOARD_UP_FUNC(unsigned char key, int x, int y)
{
	Keyboard::SetKey((EKeyCode)key, false);
	s_instance->OnKeyReleased(Key((EKeyCode)key, key));
}

/*static*/ void Application::__internal_MOUSE_FUNC(int button, int state, int x, int y)
{
	// TODO : register new mouse state
	EMouseButton mouseButton = e_mouse_button_count;
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		mouseButton = e_mouse_button_left;
		break;
	case GLUT_RIGHT_BUTTON:
		mouseButton = e_mouse_button_right;
		break;
	case GLUT_MIDDLE_BUTTON:
		mouseButton = e_mouse_button_middle;
		break;
	default:
		return;
	}
	if(GLUT_UP == state)
	{
		s_instance->OnMouseButtonReleased(mouseButton, x, y);
	}
	else
	{
		s_instance->OnMouseButtonPressed(mouseButton, x, y);
	}
}

/*static*/ void Application::__internal_MOTION_FUNC(int x, int y)
{
	// TODO : register new mouse state
	s_instance->OnMouseMoved(x, y);
}

/*static*/ void Application::__internal_PASSIVE_MOTION_FUNC(int x, int y)
{
	__internal_MOTION_FUNC(x, y);
}

/*static*/ void Application::__internal_VISIBILITY_FUNC(int state)
{
	// Nothing to do for now
}

/*static*/ void Application::__internal_ENTRY_FUNC(int state)
{
	// Nothing to do for now
}

/*static*/ void Application::__internal_SPECIAL_FUNC(int key, int x, int y)
{
	if(GLUT_KEY_F1 <= key && GLUT_KEY_F12 >= key)
	{
		key = key - key - GLUT_KEY_F1 + e_key_f1;
	}
	else if(GLUT_KEY_LEFT <= key && GLUT_KEY_INSERT >= key)
	{
		key = key - GLUT_KEY_LEFT + e_key_left;
	}
	Keyboard::SetKey((EKeyCode)key, true);
	s_instance->OnKeyPressed(Key((EKeyCode)(key), (unsigned char)0));
}

/*static*/ void Application::__internal_SPECIAL_UP_FUNC(int key, int x, int y)
{
	if(GLUT_KEY_F1 <= key && GLUT_KEY_F12 >= key)
	{
		key = key - key - GLUT_KEY_F1 + e_key_f1;
	}
	else if(GLUT_KEY_LEFT <= key && GLUT_KEY_INSERT >= key)
	{
		key = key - GLUT_KEY_LEFT + e_key_left;
	}
	Keyboard::SetKey((EKeyCode)key, false);
	s_instance->OnKeyReleased(Key((EKeyCode)(key), (unsigned char)0));
}

/*static*/ void Application::__internal_IDLE_FUNC()
{
	Keyboard::UpdateModifiers();
	if(Keyboard::IsShiftStateChanged())
	{
		if(Keyboard::IsShiftPressed())
		{
			Keyboard::SetKey(e_key_shift, true);
			s_instance->OnKeyPressed(Key(e_key_shift, 0));
		}
		else
		{
			Keyboard::SetKey(e_key_shift, false);
			s_instance->OnKeyReleased(Key(e_key_shift, 0));
		}
	}
	if(Keyboard::IsCtrlStateChanged())
	{
		if(Keyboard::IsCtrlPressed())
		{
			Keyboard::SetKey(e_key_ctrl, true);
			s_instance->OnKeyPressed(Key(e_key_ctrl, 0));
		}
		else
		{
			Keyboard::SetKey(e_key_ctrl, false);
			s_instance->OnKeyReleased(Key(e_key_ctrl, 0));
		}
	}
	if(Keyboard::IsAltStateChanged())
	{
		if(Keyboard::IsAltPressed())
		{
			Keyboard::SetKey(e_key_alt, true);
			s_instance->OnKeyPressed(Key(e_key_alt, 0));
		}
		else
		{
			Keyboard::SetKey(e_key_alt, false);
			s_instance->OnKeyReleased(Key(e_key_alt, 0));
		}
	}
	glutPostRedisplay();
}

/*static*/ void Application::__internal_RELEASE()
{
	s_instance->OnRelease();
}
