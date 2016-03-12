#include <Light.hpp>

/*explicit*/ Light::Light(Vector3f position, ColorRGBA ambiant, ColorRGBA diffuse, ColorRGBA specular, ELightAttenuation attenuationType, float currentAttenuation) 
	:m_position(position)
	 ,m_ambiant(ambiant)
	 ,m_diffuse(diffuse)
	 ,m_specular(specular)
	 ,m_attenuationType(attenuationType)
	 ,m_currentAttenuation(currentAttenuation)
{

}

/*explicit*/ Light::Light() 
	:m_position(0.0f, 0.0f, 0.0f)
	 ,m_ambiant(0.0f, 0.0f, 0.0f, 0.0f)
	 ,m_diffuse(1.0f, 1.0f, 1.0f, 1.0f)
	 ,m_specular(0.0f, 0.0f, 0.0f, 0.0f)
	 ,m_attenuationType(CONSTANT)
	 ,m_currentAttenuation(1.0f)
{

}

/*virtual*/ void Light::SetPosition(Vector3f pos)
{
	m_position = pos;
}

/*virtual*/ Vector3f Light::GetPosition()
{
	return m_position;
}

/*virtual*/ void Light::SetAmbiantLight(ColorRGBA color)
{
	m_ambiant = color;
}

/*virtual*/ void Light::SetDiffuseLight(ColorRGBA color)
{
	m_diffuse = color;
}

/*virtual*/ void Light::SetSpecularLight(ColorRGBA color)
{
	m_specular = color;
}

/*virtual*/ void Light::SetAttenuation(ELightAttenuation type, float value)
{
	m_attenuationType = type;
	m_currentAttenuation = value;
}

/*explicit*/ SpotLight::SpotLight() 
	: Light()
	,m_cutoff(90)
{

}

/*explicit*/ SpotLight::SpotLight(Vector3f position
	,ColorRGBA ambiant
	,ColorRGBA diffuse
	,ColorRGBA specular
	,ELightAttenuation attenuationType
	,float currentAttenuation
	,float cutOff
)
	: Light(position, ambiant, diffuse, specular, attenuationType, currentAttenuation)
	, m_cutoff(cutOff)
{

}

/*explicit*/ void SpotLight::setCutOff(float value)
{

}

/*explicit*/ DirectionalLight::DirectionalLight() 
	: Light()
	,m_direction(1.0f, 0.0f, 0.0f)
{

}

/*explicit*/ DirectionalLight::DirectionalLight(Vector3f position
	,ColorRGBA ambiant
	,ColorRGBA diffuse
	,ColorRGBA specular
	,ELightAttenuation attenuationType
	,float currentAttenuation
	,float direction
)
	: Light(position, ambiant, diffuse, specular, attenuationType, currentAttenuation)
	, m_cutoff(direction )
{

}

/*explicit*/ void DirectionalLight::setDirection(Vector3d value)
{
	m_direction = value;
}