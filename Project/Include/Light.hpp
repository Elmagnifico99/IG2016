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

#include <Vector.hpp>

enum ELightAttenuation
{
	CONSTANT,
	LINEAR,
	QUADRATIC
};

class Light
{
public :
	explicit Light();
	
	explicit SetPosition(Vector3f pos);

	explicit SetAmbiantLight(ColorRGBA color);
	explicit SetDiffuseLight(ColorRGBA color);
	explicit SetSpecularLight(ColorRGBA color);

	explicit SetAttenuation(ELightAttenuation type, float value);
protected :
	Vector3f m_position;

	ColorRGBA m_ambiant;
	ColorRGBA m_diffuse;
	ColorRGBA m_specular;

	ELightAttenuation m_attenuationType;

	float	m_currentAttenuation;
};

#endif // __LIGHT_H