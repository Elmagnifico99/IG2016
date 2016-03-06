#ifndef __IMAGE_HPP
#define __IMAGE_HPP

#include <PNG/png.h>

class Image
{

public:

	class Rect
	{

	public:

		explicit		Rect		(unsigned int l, unsigned int t, unsigned int w, unsigned int h);
		virtual bool	operator==	(const Rect& other);

	public:

		unsigned int left;
		unsigned int top;
		unsigned int width;
		unsigned int height;

	};

	class MemoryStream
	{

	public:

		const unsigned char*	m_bytes;
		unsigned char*			m_wbytes;
		unsigned int			m_size;
		unsigned int			m_position;

	};

public:
	
	explicit				Image			(const char* filename);
	explicit				Image			(unsigned int width, unsigned int height, unsigned int bitsPerPixels = 24);
	explicit				Image			(unsigned int width, unsigned int height, unsigned int bitsPerPixels, unsigned char* bytes);
	explicit				Image			(const Image& toCopy);
	virtual					~Image			(void);

	virtual void			Initialize		(unsigned char v1, unsigned char v2 = 0, unsigned char v3 = 0, unsigned char v4 = 0);

	virtual bool			Load			(const char* filename);
	virtual bool			LoadFromMemory	(const unsigned char* memory, unsigned int size);
	virtual bool			Save			(const char* filename);
	virtual bool			SaveToMemory	(unsigned char* memory, unsigned int& size, bool fixedSize = false, unsigned int fsize = 0);

	virtual unsigned int	GetBPP			(void) const;
	
	virtual bool			GetPixel		(unsigned int x, unsigned int y, unsigned char* c) const;
	virtual bool			SetPixel		(unsigned int x, unsigned int y, unsigned char* c);

	virtual unsigned char*	GetPixels		(void) const;
	virtual unsigned char*	GetPixels		(void);
	
	virtual unsigned int	GetWidth		(void) const;
	virtual unsigned int	GetHeight		(void) const;

	virtual bool			CopyImage		(const Image& toCopy, Rect& dest = Rect(0, 0, 0, 0), Rect& src = Rect(0, 0, 0, 0));
	virtual bool			IsValid			(void) const;

private:

	static void				__internal_PNG_ERROR(png_structp png_ptr, png_const_charp msg);
	static void				__internal_PNG_READ	(png_structp png_ptr, png_bytep data, png_size_t length);
	static void				__internal_PNG_WRITE(png_structp png_ptr, png_bytep data, png_size_t length);
	static void				__internal_PNG_FLUSH(png_structp png_ptr);

	bool					__internal_Load		(const char* filename, const unsigned char* memory, unsigned int size, bool fromMemory);
	bool					__internal_Save		(const char* filename, unsigned char* memory, unsigned int& size, bool toMemory, bool fixedSize = false, unsigned int fsize = 0);

protected:
	
	unsigned int	m_width;
	unsigned int	m_height;
	unsigned int	m_size;
	unsigned int	m_bitsPerPixels;
	unsigned char*	m_pixels;
	unsigned char	m_backgroundRed;
	unsigned char	m_backgroundGreen;
	unsigned char	m_backgroundBlue;
	bool			m_good;

};

#include "Image.inl"

#endif // __IMAGE_HPP