#ifndef __MATERIAL_HPP
#define __MATERIAL_HPP

#include <Config.hpp>

#include <Texture.hpp>

class Material
{
	
public:

	static const float DEFAULT_AMBIENT[];
	static const float DEFAULT_DIFFUSE[];
	static const float DEFAULT_SPECULAR[];
	static const float DEFAULT_SHININESS;

	enum ETextureColorBlendMode
	{
		e_texture_color_blend_mode_texture_only,
		e_texture_color_blend_mode_color_only,
		e_texture_color_blend_mode_texture_and_color,

		e_texture_color_blend_mode_count // Keep at the end of the enum
	};

	explicit Material(void);
	explicit Material(float* ambient, float* diffuse, float* specular, float shininess);
	explicit Material(float ambientR, float ambientG, float ambientB, float ambientA, float diffuseR, float diffuseG, float diffuseB, float diffuseA, float specularR, float specularG, float specularB, float specularA, float shininess);
	explicit Material(const Material& material);
	virtual ~Material(void);

	virtual void Enable(void) const;

	virtual void SetAmbient(float* ambient);
	virtual void SetAmbient(float ambientR, float ambientG, float ambientB, float ambientA = 1.0f);
	virtual const float* GetAmbient(void) const;

	virtual void SetDiffuse(float* diffuse);
	virtual void SetDiffuse(float diffuseR, float diffuseG, float diffuseB, float diffuseA = 1.0f);
	virtual const float* GetDiffuse(void) const;

	virtual void SetSpecular(float* specular);
	virtual void SetSpecular(float specularR, float specularG, float specularB, float specularA = 1.0f);
	virtual const float* GetSpecular(void) const;

	virtual void SetShininess(float shininess);
	virtual float GetShininess(void) const;

	virtual void SetDiffuseTexture(Texture* texture);
	virtual void SetDiffuseTexture(Texture* texture, ETextureColorBlendMode mode);
	virtual void SetDiffuseTextureColorBlendMode(ETextureColorBlendMode mode);
	virtual void RemoveDiffuseTexture(void);

	static void Disable(void);

protected:

	float m_ambient[4];
	float m_diffuse[4];
	float m_specular[4];
	float m_shininess;

	Texture* m_ambientTexture; // Not supported yet / Needs shaders
	Texture* m_diffuseTexture;
	Texture* m_specularTexture; // Not supported yet / Needs shaders

	Texture* m_bumpmapTexture; // Not supported yet / Needs shaders
	Texture* m_displacementTexture; // Not supported yet // Needs shaders

	ETextureColorBlendMode m_ambientBlend; // Not supported yet // Needs shaders
	ETextureColorBlendMode m_diffuseBlend;
	ETextureColorBlendMode m_specularBlend; // Not supported yet // Needs shaders

};

#ifndef NO_INLINE
#include "Material.inl"
#endif // NO_INLINE

#endif // __MATERIAL_HPP