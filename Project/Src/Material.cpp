#include <Material.hpp>
#include <GL/gl.h>

#ifdef NO_INLINE
#include <Material.inl>
#endif

/*static*/ const float Material::DEFAULT_AMBIENT[] = { 0.0f, 0.0f, 0.0f, 1.0f };
/*static*/ const float Material::DEFAULT_DIFFUSE[] = { 1.0f, 1.0f, 1.0f, 1.0f };
/*static*/ const float Material::DEFAULT_SPECULAR[] = { 0.25f, 0.25f, 0.25f, 1.0f };
/*static*/ const float Material::DEFAULT_SHININESS = 0.5f;

/*explicit*/ Material::Material()
	: m_ambientTexture(nullptr) // Not supported yet / Needs shaders
	, m_diffuseTexture(nullptr)
	, m_specularTexture(nullptr) // Not supported yet / Needs shaders
	, m_bumpmapTexture(nullptr) // Not supported yet / Needs shaders
	, m_displacementTexture(nullptr) // Not supported yet // Needs shaders
	, m_ambientBlend(e_texture_color_blend_mode_texture_and_color) // Not supported yet // Needs shaders
	, m_diffuseBlend(e_texture_color_blend_mode_texture_and_color)
	, m_specularBlend(e_texture_color_blend_mode_texture_and_color) // Not supported yet // Needs shaders
{
	m_ambient[0] = DEFAULT_AMBIENT[0];
	m_ambient[1] = DEFAULT_AMBIENT[1];
	m_ambient[2] = DEFAULT_AMBIENT[2];
	m_ambient[3] = DEFAULT_AMBIENT[3];
	m_diffuse[0] = DEFAULT_DIFFUSE[0];
	m_diffuse[1] = DEFAULT_DIFFUSE[1];
	m_diffuse[2] = DEFAULT_DIFFUSE[2];
	m_diffuse[3] = DEFAULT_DIFFUSE[3];
	m_specular[0] = DEFAULT_SPECULAR[0];
	m_specular[1] = DEFAULT_SPECULAR[1];
	m_specular[2] = DEFAULT_SPECULAR[2];
	m_specular[3] = DEFAULT_SPECULAR[3];
	m_shininess = DEFAULT_SHININESS;
}

/*explicit*/ Material::Material(float* ambient, float* diffuse, float* specular, float shininess)
	: m_ambientTexture(nullptr) // Not supported yet / Needs shaders
	, m_diffuseTexture(nullptr)
	, m_specularTexture(nullptr) // Not supported yet / Needs shaders
	, m_bumpmapTexture(nullptr) // Not supported yet / Needs shaders
	, m_displacementTexture(nullptr) // Not supported yet // Needs shaders
	, m_ambientBlend(e_texture_color_blend_mode_texture_and_color) // Not supported yet // Needs shaders
	, m_diffuseBlend(e_texture_color_blend_mode_texture_and_color)
	, m_specularBlend(e_texture_color_blend_mode_texture_and_color) // Not supported yet // Needs shaders
{
	m_ambient[0] = ambient[0];
	m_ambient[1] = ambient[1];
	m_ambient[2] = ambient[2];
	m_ambient[3] = ambient[3];
	m_diffuse[0] = diffuse[0];
	m_diffuse[1] = diffuse[1];
	m_diffuse[2] = diffuse[2];
	m_diffuse[3] = diffuse[3];
	m_specular[0] = specular[0];
	m_specular[1] = specular[1];
	m_specular[2] = specular[2];
	m_specular[3] = specular[3];
	m_shininess = shininess;
}

/*explicit*/ Material::Material(float ambientR, float ambientG, float ambientB, float ambientA, float diffuseR, float diffuseG, float diffuseB, float diffuseA, float specularR, float specularG, float specularB, float specularA, float shininess)
	: m_ambientTexture(nullptr) // Not supported yet / Needs shaders
	, m_diffuseTexture(nullptr)
	, m_specularTexture(nullptr) // Not supported yet / Needs shaders
	, m_bumpmapTexture(nullptr) // Not supported yet / Needs shaders
	, m_displacementTexture(nullptr) // Not supported yet // Needs shaders
	, m_ambientBlend(e_texture_color_blend_mode_texture_and_color) // Not supported yet // Needs shaders
	, m_diffuseBlend(e_texture_color_blend_mode_texture_and_color)
	, m_specularBlend(e_texture_color_blend_mode_texture_and_color) // Not supported yet // Needs shaders
{
	m_ambient[0] = ambientR;
	m_ambient[1] = ambientG;
	m_ambient[2] = ambientB;
	m_ambient[3] = ambientA;
	m_diffuse[0] = diffuseR;
	m_diffuse[1] = diffuseG;
	m_diffuse[2] = diffuseB;
	m_diffuse[3] = diffuseA;
	m_specular[0] = specularR;
	m_specular[1] = specularG;
	m_specular[2] = specularB;
	m_specular[3] = specularA;
	m_shininess = shininess;
}

/*explicit*/ Material::Material(const Material& material)
	: m_shininess(material.m_shininess)
	, m_ambientTexture(material.m_ambientTexture) // Not supported yet / Needs shaders
	, m_diffuseTexture(material.m_diffuseTexture)
	, m_specularTexture(material.m_specularTexture) // Not supported yet / Needs shaders
	, m_bumpmapTexture(material.m_bumpmapTexture) // Not supported yet / Needs shaders
	, m_displacementTexture(material.m_displacementTexture) // Not supported yet // Needs shaders
	, m_ambientBlend(material.m_ambientBlend) // Not supported yet // Needs shaders
	, m_diffuseBlend(material.m_diffuseBlend)
	, m_specularBlend(material.m_specularBlend) // Not supported yet // Needs shaders
{
	m_ambient[0] = material.m_ambient[0];
	m_ambient[1] = material.m_ambient[1];
	m_ambient[2] = material.m_ambient[2];
	m_ambient[3] = material.m_ambient[3];
	m_diffuse[0] = material.m_diffuse[0];
	m_diffuse[1] = material.m_diffuse[1];
	m_diffuse[2] = material.m_diffuse[2];
	m_diffuse[3] = material.m_diffuse[3];
	m_specular[0] = material.m_specular[0];
	m_specular[1] = material.m_specular[1];
	m_specular[2] = material.m_specular[2];
	m_specular[3] = material.m_specular[3];
}

/*virtual*/ void Material::Enable() const
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_ambient);
	if(nullptr != m_diffuseTexture)
	{
		if(e_texture_color_blend_mode_texture_only == m_diffuseBlend)
		{
			glMaterialfv(GL_FRONT, GL_DIFFUSE, DEFAULT_DIFFUSE);
		}
		else
		{
			glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
		}
		if(e_texture_color_blend_mode_color_only == m_diffuseBlend)
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		else
		{
			m_diffuseTexture->Enable();
		}
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diffuse);
	}
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, &m_shininess);
}

/*virtual*/ void Material::SetAmbient(float* ambient)
{
	m_ambient[0] = ambient[0];
	m_ambient[1] = ambient[1];
	m_ambient[2] = ambient[2];
	m_ambient[3] = ambient[3];
}

/*virtual*/ void Material::SetAmbient(float ambientR, float ambientG, float ambientB, float ambientA)
{
	m_ambient[0] = ambientR;
	m_ambient[1] = ambientG;
	m_ambient[2] = ambientB;
	m_ambient[3] = ambientA;
}

/*virtual*/ void Material::SetDiffuse(float* diffuse)
{
	m_diffuse[0] = diffuse[0];
	m_diffuse[1] = diffuse[1];
	m_diffuse[2] = diffuse[2];
	m_diffuse[3] = diffuse[3];
}

/*virtual*/ void Material::SetDiffuse(float diffuseR, float diffuseG, float diffuseB, float diffuseA)
{
	m_diffuse[0] = diffuseR;
	m_diffuse[1] = diffuseG;
	m_diffuse[2] = diffuseB;
	m_diffuse[3] = diffuseA;
}

/*virtual*/ void Material::SetSpecular(float* specular)
{
	m_specular[0] = specular[0];
	m_specular[1] = specular[1];
	m_specular[2] = specular[2];
	m_specular[3] = specular[3];
}

/*virtual*/ void Material::SetSpecular(float specularR, float specularG, float specularB, float specularA)
{
	m_specular[0] = specularR;
	m_specular[1] = specularG;
	m_specular[2] = specularB;
	m_specular[3] = specularA;
}

/*virtual*/ void Material::SetDiffuseTexture(Texture* texture, ETextureColorBlendMode mode)
{
	m_diffuseTexture = texture;
	m_diffuseBlend = mode;
}

/*virtual*/ void Material::SetDiffuseTextureColorBlendMode(ETextureColorBlendMode mode)
{
	if(mode != e_texture_color_blend_mode_count)
	{
		m_diffuseBlend = mode;
	}
}

/*static*/ void Material::Disable()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, DEFAULT_AMBIENT);
	glBindTexture(GL_TEXTURE_2D, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, DEFAULT_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, DEFAULT_SPECULAR);
	glMaterialfv(GL_FRONT, GL_SHININESS, &DEFAULT_SHININESS);
}
