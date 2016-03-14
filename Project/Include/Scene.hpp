#ifndef __SCENE_HPP
#define __SCENE_HPP

#include <Node.hpp>
#include <Light.hpp>
#include <Leaf.hpp>
#include <vector>

class Scene
{

public:

	class RootNode : public Node 
	{
		virtual void ApplyTransformation	(void);
		virtual void Dump					(std::string tab, unsigned int tabCount);
	};

	explicit					Scene			(void);
	virtual						~Scene			(void);

	virtual Node*				GetRootNode		(void) const;
	virtual void				Render			(void);

	virtual void				Save			(const char* filename);
	virtual void				Load			(const char* filename);

	virtual DirectionalLight*	GetSunLight		(void) const;
	virtual void				SetLightCount	(unsigned int count);

protected:

	virtual void				PrepareLights	(void);

	Node*						m_rootNode;
	std::vector<LightLeaf*>		m_lights;
	//std::vector<CameraLeaf*>		m_cameras;

	DirectionalLight*			m_sunLight;
	unsigned int				m_lightCount;

};

#endif //__SCENE_HPP