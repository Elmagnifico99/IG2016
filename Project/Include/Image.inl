#include <Image.hpp>

/*virtual*/ inline Image::~Image()
{
	if(nullptr != m_pixels)
	{
		delete[](m_pixels);
	}
}

/*virtual*/ inline unsigned int Image::GetBPP() const
{
	return m_bitsPerPixels;
}

/*virtual*/ inline unsigned char* Image::GetPixels() const
{
	return m_pixels;
}

/*virtual*/ inline unsigned char* Image::GetPixels()
{
	return m_pixels;
}

/*explicit*/ inline Image::Rect::Rect(unsigned int l, unsigned int t, unsigned int w, unsigned int h)
	: left(l)
	, top(t)
	, width(w)
	, height(h) 
{
		
}

/*virtual*/ inline bool Image::Rect::operator==(const Rect& other)
{
	return left == other.left && top == other.top && width == other.width && height == other.height;
}

/*virtual*/ inline unsigned int Image::GetWidth() const
{
	return m_width;
}

/*virtual*/ inline unsigned int Image::GetHeight() const
{
	return m_height;
}

/*virtual*/ inline bool Image::IsValid() const
{
	return m_good;
}
