#include <Texture.hpp>

#include <GL/gl.h>

/*explicit*/ Texture::Texture(const char* file)
	: m_identifier(0)
	, m_smooth(false)
	, m_clampRepeat(true)
{
	Initialize();
	Image image(file);
	SetImage(image);
	m_smooth = !m_smooth;
	m_clampRepeat = !m_clampRepeat;
	SetSmoothEnabled(!m_smooth);
	SetClampRepeat(!m_clampRepeat);
	AddReference(m_identifier);
}

/*explicit*/ /*Texture::Texture(unsigned int width, unsigned int height)
	: m_identifier(0)
	, m_smooth(false)
	, m_clampRepeat(true)
{

}*/

/*explicit*/ Texture::Texture(const Image& image)
	: m_identifier(0)
	, m_smooth(false)
	, m_clampRepeat(true)
{
	Initialize();
	m_smooth = !m_smooth;
	m_clampRepeat = !m_clampRepeat;
	SetSmoothEnabled(!m_smooth);
	SetClampRepeat(!m_clampRepeat);
	AddReference(m_identifier);
	SetImage(image);
}

/*explicit*/ Texture::Texture(const Texture& texture)
	: m_identifier(texture.m_identifier)
	, m_smooth(!texture.m_smooth)
	, m_clampRepeat(!texture.m_clampRepeat)
{
	Initialize();
	AddReference(m_identifier);
	SetSmoothEnabled(!m_smooth);
	SetClampRepeat(!m_clampRepeat);
}

/*virtual*/ void Texture::SetSmoothEnabled(bool state)
{
	if(state != m_smooth)
	{
		m_smooth = state;
		Enable();
		if(m_smooth)
		{
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		}
		else
		{
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		}
	}
}

/*virtual*/ void Texture::SetImage(const Image& image)
{
	if(!image.IsValid())
	{
		return;
	}
	DeleteReference(m_identifier);
	glGenTextures(1, &m_identifier);
	glBindTexture(GL_TEXTURE_2D, m_identifier);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, image.GetWidth(), image.GetHeight(), 0, 
		((image.GetBPP() == 24)?GL_RGB:GL_RGBA), GL_UNSIGNED_BYTE, image.GetPixels());
	AddReference(m_identifier);
}

/*virtual*/ void Texture::SetClampRepeat(bool state)
{
	if(state != m_clampRepeat)
	{
		m_clampRepeat = state;
		Enable();
		if(m_clampRepeat)
		{
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
		else
		{
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		}
	}
}

/*static*/ bool Texture::s_texturesInitialized = false;

/*static*/ std::map<unsigned int, unsigned int> Texture::s_references;

/*static*/ void Texture::Initialize()
{
	if(!s_texturesInitialized)
	{
		glEnable(GL_TEXTURE_2D);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
		s_texturesInitialized = true;
	}
}

/*static*/ void Texture::AddReference(unsigned int identifier)
{
	if(s_references.end() == s_references.find(identifier))
	{
		s_references[identifier] = 0;
	}
	s_references[identifier]++;
}

/*static*/ void Texture::DeleteReference(unsigned int identifier)
{
	std::map<unsigned int, unsigned int>::iterator it = s_references.find(identifier);
	if(s_references.end() != it)
	{
		it->second--;
		if(0 == it->second)
		{
			s_references.erase(it);
			if(0 != identifier)
			{
				glDeleteTextures(1, &identifier);
			}
		}
	}
}
