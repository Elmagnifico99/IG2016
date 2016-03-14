#include <Scene.hpp>
#include <iostream>
#include <GL/gl.h>

/*virtual*/ void Scene::RootNode::ApplyTransformation(void) {}

/*virtual*/ void Scene::RootNode::Dump(std::string tab, unsigned int tabCount)
{
	for(register unsigned int i = 0; i < tabCount; ++i)
	{
		std::cout << tab;
	}
	std::cout << "ROOT_NODE";
	DumpChildren(tab, tabCount);
}

/*explicit*/ Scene::Scene()
{
	m_rootNode = new RootNode();
}

/*virtual*/ Scene::~Scene()
{
	while(0 != m_rootNode->GetChildNodeCount() || 0 != m_rootNode->GetChildLeafCount())
	{
		m_rootNode->ClearAllChildren();
	}
	if(NULL != m_rootNode)
	{
		delete(m_rootNode);
	}
}

/*explicit*/ Node* Scene::GetRootNode() const
{
	return m_rootNode;
}

/*explicit*/ void Scene::Render()
{
	m_rootNode->Render();
}

/*virtual*/ void Scene::Save(const char* filename)
{

}

/*virtual*/ void Scene::Load(const char* fileName)
{

}

/*virtual*/ DirectionalLight* Scene::GetSunLight(void) const
{
	return m_sunLight;
}

/*virtual*/ void Scene::SetLightCount(unsigned int count)
{
	int c;
	glGetIntegerv(GL_MAX_LIGHTS, &c);
	if(0 < count)
	{
		if(c > count)
		{
			m_lightCount = count;
		}
		else
		{
			m_lightCount = c - 1;
		}
	}
	else
	{
		m_lightCount = 0;
	}
}

/*virtual*/ void Scene::PrepareLights()
{
	for(std::vector<LightLeaf*>::iterator it = m_lights.begin(); it != m_lights.end(); ++it)
	{
		if((*it)->IsEnabled())
		{
			Light* light = (*it)->GetLight();
			if(nullptr != light && light->IsEnabled())
			{

			}
		}
	}
}