#ifndef __SCENE_HPP
#define __SCENE_HPP

#include <Node.hpp>
class Scene
{

public :
	class RootNode:public Node 
	{
		virtual void ApplyTransformation	(void);
		virtual void Dump					(std::string tab, unsigned int tabCount);
	};

	explicit	Scene();
	virtual		~Scene();

	virtual Node* GetRootNode();
	virtual void Render();

protected :
	Node* m_rootNode;
	//std::vector<LightLeaf*>		m_lights;
	//std::vector<CameraLeaf*>		m_cameras;
};

#endif //__SCENE_HPP