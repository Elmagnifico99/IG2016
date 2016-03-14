#ifndef __TEXTURE_HPP
#define __TEXTURE_HPP

#include <Config.hpp>

#include <Image.hpp>

#include <map>

class Texture
{
	
public:

	explicit Texture(const char* file);
	//explicit Texture(unsigned int width, unsigned int height);
	explicit Texture(const Image& image);
	explicit Texture(const Texture& texture);
	virtual ~Texture(void);

	virtual void Enable(void) const;

	virtual unsigned int GetIdentifier(void) const;

	virtual void SetSmoothEnabled(bool state);
	virtual bool IsSmoothEnabled(void) const;

	virtual void SetImage(const Image& image);

	virtual void SetClampRepeat(bool state);
	virtual bool IsClampRepeat(void) const;

protected:

	unsigned int m_identifier;
	bool m_smooth;
	bool m_clampRepeat;

private:

	static void Initialize(void);

	static void AddReference(unsigned int identifier);
	static void DeleteReference(unsigned int identifier);

	static bool s_texturesInitialized;
	static std::map<unsigned int, unsigned int> s_references;

};

#ifndef NO_INLINE
#include "Texture.inl"
#endif // NO_INLINE

#endif // __TEXTURE_HPP