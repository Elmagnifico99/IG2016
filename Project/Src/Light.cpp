#include <Light.hpp>

/*explicit*/ Light::Light()
{

}

/*explicit*/ Light::SetPosition(Vector3f pos)
{
	m_position = pos;
}

/*explicit*/ Light::SetAmbiantLight(ColorRGBA color)
{
	m_ambiant = color;
}

/*explicit*/ Light::SetDiffuseLight(ColorRGBA color)
{
	m_diffuse = color;
}

/*explicit*/ Light::SetSpecularLight(ColorRGBA color)
{
	m_specular = color;
}

/*explicit*/ Light::SetAttenuation(ELightAttenuation type, float value)
{
	m_attenuationType = type;
	m_currentAttenuation = value;
}