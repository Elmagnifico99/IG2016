#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP

#include <Keyboard.hpp>
#include <Mouse.hpp>
#include <string>

class Application
{

public:

	class Parameters
	{
	public:
		explicit		Parameters(void);
		std::string		WindowTitle;
		unsigned int	Width;
		unsigned int	Height;
		bool			CenterWindow;
		int				PositionX;
		int				PositionY;
		bool			EnableDepthBuffer;
		bool			EnableStencilBuffer;
		bool			DoubleBuffering;
		bool			IndexedColors;
		bool			EnableMultiSampling;
		bool			EnableStereo;
		bool			FullScreen;
		bool			FixedSize;
		bool			EnableOverlay;
	};

public:

	explicit		Application				(void);
	virtual			~Application			(void);

	virtual void	OnInitialize			(int argc, char** argv);

	virtual void	OnUpdate				(float deltaTimeInSeconds);
	virtual void	OnResizingWindow		(unsigned int width, unsigned int height);

	virtual void	OnKeyPressed			(Key key);
	virtual void	OnKeyReleased			(Key key);

	virtual void	OnMouseButtonPressed	(EMouseButton button, int positionX, int positionY);
	virtual void	OnMouseButtonReleased	(EMouseButton button, int positionX, int positionY);
	virtual void	OnMouseMoved			(int positionX, int positionY);
	virtual void	OnMouseScrolled			(int delta, int positionX, int positionY);

	virtual void	OnRelease				(void);

	virtual void	ResizeWindow			(unsigned int width, unsigned int height);

	bool			Start					(int argc, char** argv, const Parameters& parameters = Parameters());
	void			Close					(void) const;

public:

	static void __internal_OVERLAY_DISPLAY_FUNC	(void);
	static void __internal_DISPLAY_FUNC			(void);
	static void __internal_RESHAPE_FUNC			(int width, int height);
	static void __internal_KEYBOARD_FUNC		(unsigned char key, int x, int y);
	static void __internal_KEYBOARD_UP_FUNC		(unsigned char key, int x, int y);
	static void __internal_MOUSE_FUNC			(int button, int state, int x, int y);
	static void __internal_MOTION_FUNC			(int x, int y);
	static void __internal_PASSIVE_MOTION_FUNC	(int x, int y);
	static void __internal_VISIBILITY_FUNC		(int state);
	static void __internal_ENTRY_FUNC			(int state);
	static void __internal_SPECIAL_FUNC			(int key, int x, int y);
	static void __internal_SPECIAL_UP_FUNC		(int key, int x, int y);
	static void __internal_IDLE_FUNC			(void);
	static void __internal_RELEASE				(void);

protected:

	static Application* s_instance;

	bool				m_fixedSize;
	unsigned int		m_width;
	unsigned int		m_height;

};

#include "Application.inl"

#endif // __APPLICATION_HPP