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

#ifdef NO_INLINE
#include <Application.inl>
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
	if(m_fixedSize)
	{
		s_instance->OnResizingWindow((unsigned int)width, (unsigned int)height);
	}
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

	m_timeElapsed = glutGet(GLUT_ELAPSED_TIME);
	OnInitialize(argc, argv, parameters);

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

	glViewport(0,0,parameters.Width,parameters.Height);

	Keyboard::Initialize();
	Mouse::Initialize();
	glutMainLoop();
	return true;
}

void Application::Close() const
{
	exit(0);
}

/*static*/ void Application::__internal_DISPLAY_FUNC()
{
	register unsigned int tmp = s_instance->m_timeElapsed;
	s_instance->m_timeElapsed = glutGet(GLUT_ELAPSED_TIME);
	s_instance->OnUpdate((s_instance->m_timeElapsed - tmp) / 1000.0f);
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


// Doxygen documentation
/**
 * \file Application.hpp
 * \brief Contains the Application class definition.
 * \author Joseph Kieffer
 * \version 0.1
 */

/**
 * \class Application 
 * \brief The entry point class of the Application.
 * 
 * This class contains the input and drawing callbacks. 
 * It must be inherited to provide user specific behavior.
 *
 * 
 */

/**
 * \class Application::Parameters
 * \brief The set of parameters sent to the Application
 *
 * This class contains informations that are sent to the 
 * Application::Start method. 
 */

/**
 * \fn explicit Application::Parameters::Parameters(void)
 * \brief Default constructor
 *
 * Construct the parameters with the default values
 */

/**
 * \var std::string Application::Parameters::WindowTitle
 *
 * \brief The title of the window. Default is "OpenGL Application".
 */

/**
 * \var unsigned int Application::Parameters::Width
 *
 * \brief The width of the window. Default is 800.
 */

/**
 * \var unsigned int Application::Parameters::Height
 *
 * \brief The height of the window. Default is 600.
 */

/**
 * \var bool Application::Parameters::CenterWindow
 *
 * \brief Set to true to center the Window. Default is true.
 */

/**
 * \var int	Application::Parameters::PositionX
 *
 * \brief The X position of the window, disabled if CenterWindow is true. Default is 0.
 */

/**
 * \var int Application::Parameters::PositionY
 *
 * \brief The Y position of the window, disabled if CenterWindow is true. Default is 0.
 */

/**
 * \var bool Application::Parameters::EnableDepthBuffer
 *
 * \brief Enable depth testing. Default is true.
 */

/**
 * \var bool Application::Parameters::EnableStencilBuffer
 *
 * \brief Enable the stencil buffer. Default is false.
 */

/**
 * \var bool Application::Parameters::DoubleBuffering
 *
 * \brief Enable double buffering. Default is true.
 */

/**
 * \var bool Application::Parameters::IndexedColors
 *
 * \brief Set colors as Indexed. If false, colors are set to RGBA. Default is false.
 */

/**
 * \var bool Application::Parameters::EnableMultiSampling
 *
 * \brief Enable multi-sampling. Default is false.
 */

/**
 * \var bool Application::Parameters::EnableStereo
 *
 * \brief Enable stereo image. Default is false.
 */

/**
 * \var bool Application::Parameters::FullScreen
 *
 * \brief Set window to fullscreen. Default is false.
 */

/**
 * \var bool Application::Parameters::FixedSize
 *
 * \brief Disable window resizing. Default is false.
 */

/**
 * \var bool Application::Parameters::EnableOverlay
 *
 * \brief Enable an overlay on the window. Default is false.
 */

/**
 * \fn explicit Application::Application(void)
 *
 * \brief Default constructor of the Application.
 */

/**
 * \fn virtual Application::~Application(void)
 *
 * \brief Destructor of the Application.
 */

/**
 * \fn virtual void Application::OnInitialize(int argc, char** argv)
 *
 * \brief Method called when initializing Application.
 *
 * This function is called just after the initializing of the GL environment.
 *
 * \param argc The number of arguments of the command line.
 * \param argv The array of arguments of the command line.
 */

/**
 * \fn virtual void Application::OnUpdate(float deltaTimeInSeconds)
 *
 * \brief Method called at each frame.
 *
 * This function is called before the redrawing of the screen.
 *
 * \param deltaTimeInSeconds The number of seconds elapsed since the last call of this function.
 */

/**
 * \fn virtual void Application::OnResizingWindow(unsigned int width, unsigned int height)
 *
 * \brief Method called when resizing window.
 *
 * This function is called when the user reshape the window. This function is not called if 
 * parameters are given with FixedSize set to true, but is still called if the Application::ResizeWindow
 * methid is called. If you want to switch between sizeable and fixed size, consider setting FixedSize 
 * to false and handle window size in this function.
 *
 * \param width The new width of the window.
 * \param heightr The new height of the window.
 */

/**
 * \fn virtual void Application::OnKeyPressed(Key key)
 *
 * \brief Method called when a key is pressed.
 *
 * This function is called when a key is pressed. This keys includes all printable characters,
 * function keys, arrow keys and shift/ctrl/alt keys. 
 *
 * \bug This function make differentiation of uppercase and lowercase character, and also
 * characters that change when modifier keys are pressed.
 *
 * \param key The key pressed.
 */

/**
 * \fn virtual void Application::OnKeyReleased(Key key)
 *
 * \brief Method called when a key is released.
 *
 * This function is called when a key is released. This keys includes all printable characters,
 * function keys, arrow keys and shift/ctrl/alt keys. 
 *
 * \bug This function make differentiation of uppercase and lowercase character, and also
 * characters that change when modifier keys are pressed.
 *
 * \param key The key released.
 */

/**
 * \fn virtual void Application::OnMouseButtonPressed(EMouseButton button, int positionX, int positionY)
 *
 * \brief Method called when a mouse button is pressed.
 *
 * This function is called when a mouse button is pressed. The button parameter can be e_mouse_button_left,
 * e_mouse_button_right or e_mouse_button_middle. The function also provides the position of the mouse.
 *
 * \param button The button of the mouse that is pressed.
 * \param positionX The x position of the mouse.
 * \param positionY The y position of the mouse.
 */

/**
 * \fn virtual void Application::OnMouseButtonReleased(EMouseButton button, int positionX, int positionY)
 *
 * \brief Method called when a mouse button is released.
 *
 * This function is called when a mouse button is released. The button parameter can be e_mouse_button_left,
 * e_mouse_button_right or e_mouse_button_middle. The function also provides the position of the mouse.
 *
 * \param button The button of the mouse that is released.
 * \param positionX The x position of the mouse.
 * \param positionY The y position of the mouse.
 */

/**
 * \fn virtual void Application::OnMouseMoved(int positionX, int positionY)
 *
 * \brief Method called when the mouse is moved.
 * 
 * This function is called when the mouse cursor move.
 *
 * \param positionX The x position of the mouse.
 * \param positionY The y position of the mouse.
 */

/**
 * \fn virtual void Application::OnMouseScrolled(int delta, int positionX, int positionY)
 *
 * \brief Method called when the mouse wheel is scrolled.
 *
 * This function is called when the mouse wheel is scrolled. If the delta value is positive,
 * then the mouse wheel is scrolled forward away from the user. If the value is negative,
 * then the mouse wheel is scrolled toward the user.
 *
 * \bug This feature is not yet supported due to a miss in the glut API.
 *
 * \param delta The delta value of the mouse wheel scrolling.
 * \param positionX The x position of the mouse.
 * \param positionY The y position of the mouse.
 */

/**
 * \fn virtual void Application::OnRelease(void)
 *
 * \brief Method called when leaving the Application.
 *
 * This method is called when closing the Application, triggered when the window is closed or
 * by calling the Application::Close method.
 */

/**
 * \fn virtual void Application::ResizeWindow(unsigned int width, unsigned int height)
 *
 * \brief Resize the Window with the specified width and height.
 *
 * Resize the window to the specified size. The Application::OnResizingWindow method is called
 * even if FixedSize is set to true when initializing Application.
 *
 * \param width The new window width to set.
 * \param height The new window height to set.
 */

/**
 * \fn bool Application::Start(int argc, char** argv, const Parameters& parameters = Parameters())
 *
 * \brief Start the Application.
 *
 * Start the Application with the given parameters. This correspond to initializing OpenGL with the
 * given parameters, creating the window, calling the Application::OnInitialize method and then
 * run the main loop.
 *
 * \param argc The number of arguments of the command line.
 * \param argv The arguments of the command line.
 * \param parameters The parameters of creation of the window
 *
 * \return false if failed (if another instance is already running). Otherwise, this function never returns.
 */

/**
 * \fn void Application::Close(void) const
 *
 * \brief Exits the Application.
 *
 * The call to this function correspond to calling the Application::OnRelease method and leaving the Application.
 */
