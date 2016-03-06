#include <Texture.hpp>
#include <GL/gl.h>

/*virtual*/ inline Texture::~Texture()
{
	DeleteReference(m_identifier);
}

/*virtual*/ inline void Texture::Enable() const
{
	glBindTexture(GL_TEXTURE_2D, m_identifier);
}

/*virtual*/ inline unsigned int Texture::GetIdentifier() const
{
	return m_identifier;
}

/*virtual*/ inline bool Texture::IsSmoothEnabled() const
{
	return m_smooth;
}

/*virtual*/ inline bool Texture::IsClampRepeat() const
{
	return m_clampRepeat;
}