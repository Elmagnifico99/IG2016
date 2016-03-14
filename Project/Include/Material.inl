#include <Material.hpp>

/*virtual*/ INLINE Material::~Material()
{

}

/*virtual*/ INLINE const float* Material::GetAmbient() const
{
	return (float*)m_ambient;
}

/*virtual*/ INLINE const float* Material::GetDiffuse() const
{
	return (float*)m_diffuse;
}

/*virtual*/ INLINE const float* Material::GetSpecular() const
{
	return (float*)m_specular;
}

/*virtual*/ INLINE void Material::SetShininess(float shininess)
{
	m_shininess = shininess;
}

/*virtual*/ INLINE float Material::GetShininess() const
{
	return m_shininess;
}

/*virtual*/ INLINE void Material::SetDiffuseTexture(Texture* texture)
{
	SetDiffuseTexture(texture, m_diffuseBlend);
}

/*virtual*/ INLINE void Material::RemoveDiffuseTexture(void)
{
	m_diffuseTexture = nullptr;
}
