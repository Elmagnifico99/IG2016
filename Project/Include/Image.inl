#include <Image.hpp>

/*virtual*/ INLINE Image::~Image()
{
	if(nullptr != m_pixels)
	{
		delete[](m_pixels);
	}
}

/*virtual*/ INLINE unsigned int Image::GetBPP() const
{
	return m_bitsPerPixels;
}

/*virtual*/ INLINE unsigned char* Image::GetPixels() const
{
	return m_pixels;
}

/*virtual*/ INLINE unsigned char* Image::GetPixels()
{
	return m_pixels;
}

/*explicit*/ INLINE Image::Rect::Rect(unsigned int l, unsigned int t, unsigned int w, unsigned int h)
	: left(l)
	, top(t)
	, width(w)
	, height(h) 
{
		
}

/*virtual*/ INLINE bool Image::Rect::operator==(const Rect& other)
{
	return left == other.left && top == other.top && width == other.width && height == other.height;
}

/*virtual*/ INLINE unsigned int Image::GetWidth() const
{
	return m_width;
}

/*virtual*/ INLINE unsigned int Image::GetHeight() const
{
	return m_height;
}

/*virtual*/ INLINE bool Image::IsValid() const
{
	return m_good;
}

/*virtual*/ INLINE std::string Image::GetPath() const
{
	return m_file;
}
