#include <Light.hpp>

#ifdef NO_INLINE
#include <Light.inl>
#endif

/*explicit*/ Light::Light(Vector3f position, ColorRGBA ambiant, ColorRGBA diffuse, ColorRGBA specular, ELightAttenuation attenuationType, float currentAttenuation) 
	: m_position(position)
	, m_ambiant(ambiant)
	, m_diffuse(diffuse)
	, m_specular(specular)
	, m_attenuationType(attenuationType)
	, m_currentAttenuation(currentAttenuation)
{
	//Test 

}

/*explicit*/ Light::Light() 
	:m_position(0.0f, 0.0f, 0.0f)
	, m_ambiant(0.0f, 0.0f, 0.0f, 0.0f)
	, m_diffuse(1.0f, 1.0f, 1.0f, 1.0f)
	, m_specular(0.0f, 0.0f, 0.0f, 0.0f)
	, m_attenuationType(e_light_attenuation_constant)
	, m_currentAttenuation(1.0f)
{

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
	, ColorRGBA ambiant
	, ColorRGBA diffuse
	, ColorRGBA specular
	, ELightAttenuation attenuationType
	, float currentAttenuation
	, float cutOff
)
	: Light(position, ambiant, diffuse, specular, attenuationType, currentAttenuation)
	, m_cutoff(cutOff)
{

}

/*explicit*/ DirectionalLight::DirectionalLight() 
	: Light()
	,m_direction(0.0f, 0.0f, -1.0f)
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
	, m_direction(0.0f, 0.0f, -1.0f)
{

}
