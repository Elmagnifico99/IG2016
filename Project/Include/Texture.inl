#include <Texture.hpp>
#include <GL/gl.h>

/*virtual*/ INLINE Texture::~Texture()
{
	DeleteReference(m_identifier);
}

/*virtual*/ INLINE void Texture::Enable() const
{
	glBindTexture(GL_TEXTURE_2D, m_identifier);
}

/*virtual*/ INLINE unsigned int Texture::GetIdentifier() const
{
	return m_identifier;
}

/*virtual*/ INLINE bool Texture::IsSmoothEnabled() const
{
	return m_smooth;
}

/*virtual*/ INLINE bool Texture::IsClampRepeat() const
{
	return m_clampRepeat;
}