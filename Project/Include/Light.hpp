/**
	type
		SPOT_EXPONENT 0-128
		SPOT_CUTOFF 0-90deg OR 180
		CONSTANT_ATTENUATION unsignedf loat attenuationvalue
		LINEAR_ATTENUATION
		QUADRATIC_ATTENUATION

	min of 8 lights

	AMBIANT
	DIFFUSE
	SPECULAR

	Position

	SPOT_DIRECTION vecteur3D
	

*/
#ifndef __LIGHT_H
#define __LIGHT_H

#include <Config.hpp>

#include <Vector.hpp>
#include <Color.hpp>

enum ELightAttenuation
{
	e_light_attenuation_constant,
	e_light_attenuation_linear,
	e_light_attenuation_quadratic
};

class Light
{

public:

	explicit Light();
	explicit Light(Vector3f position, ColorRGBA ambiant, ColorRGBA diffuse, ColorRGBA specular, ELightAttenuation attenuationType, float currentAttenuation);

	virtual void		SetPosition		(Vector3f pos);
	virtual Vector3f	GetPosition		(void) const;

	virtual void		SetAmbiantLight	(ColorRGBA color);
	virtual void		SetDiffuseLight	(ColorRGBA color);
	virtual void		SetSpecularLight(ColorRGBA color);

	virtual void		SetAttenuation	(ELightAttenuation type, float value);

	virtual void		SetEnabled		(bool state);
	virtual bool		IsEnabled		(void) const;

protected:

	Vector3f			m_position;

	ColorRGBA			m_ambiant;
	ColorRGBA			m_diffuse;
	ColorRGBA			m_specular;

	ELightAttenuation	m_attenuationType;

	float				m_currentAttenuation;
	bool				m_enabled;
};

typedef Light PointLight;

class SpotLight : public Light
{

public:

	explicit SpotLight();
	explicit SpotLight(Vector3f position
		, ColorRGBA ambiant
		, ColorRGBA diffuse
		, ColorRGBA specular
		, ELightAttenuation attenuationType
		, float currentAttenuation
		, float cutOff);

	virtual void SetCutOff(float value);

protected:

	float m_cutoff;
};

class DirectionalLight : public Light
{

public:

	explicit DirectionalLight();
	explicit DirectionalLight(Vector3f position
		, ColorRGBA ambiant
		, ColorRGBA diffuse
		, ColorRGBA specular
		, ELightAttenuation attenuationType
		, float currentAttenuation
		, float direction);

	virtual void SetDirection(Vector3d value);

protected:

	Vector3d m_direction;
};

#ifndef NO_INLINE
#include "Light.inl"
#endif // NO_INLINE

#endif // __LIGHT_H