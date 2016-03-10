#include <Material.hpp>

/*virtual*/ inline Material::~Material()
{

}

/*virtual*/ inline const float* Material::GetAmbient() const
{
	return (float*)m_ambient;
}

/*virtual*/ inline const float* Material::GetDiffuse() const
{
	return (float*)m_diffuse;
}

/*virtual*/ inline const float* Material::GetSpecular() const
{
	return (float*)m_specular;
}

/*virtual*/ inline void Material::SetShininess(float shininess)
{
	m_shininess = shininess;
}

/*virtual*/ inline float Material::GetShininess() const
{
	return m_shininess;
}

/*virtual*/ inline void Material::SetDiffuseTexture(Texture* texture)
{
	SetDiffuseTexture(texture, m_diffuseBlend);
}

/*virtual*/ inline void Material::RemoveDiffuseTexture(void)
{
	m_diffuseTexture = nullptr;
}
