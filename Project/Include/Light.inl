#include <Light.hpp>

/*virtual*/ INLINE void Light::SetPosition(Vector3f pos)
{
	m_position = pos;
}

/*virtual*/ INLINE Vector3f Light::GetPosition() const
{
	return m_position;
}

/*virtual*/ INLINE void Light::SetAmbiantLight(ColorRGBA color)
{
	m_ambiant = color;
}

/*virtual*/ INLINE void Light::SetDiffuseLight(ColorRGBA color)
{
	m_diffuse = color;
}

/*virtual*/ INLINE void Light::SetSpecularLight(ColorRGBA color)
{
	m_specular = color;
}

/*virtual*/ void Light::SetEnabled(bool state)
{
	m_enabled = state;
}

/*virtual*/ bool Light::IsEnabled() const
{
	return m_enabled;
}

/*explicit*/ INLINE void SpotLight::SetCutOff(float value)
{
	m_cutoff = value;
}

/*explicit*/ INLINE void DirectionalLight::SetDirection(Vector3d value)
{
	m_direction = value;
}