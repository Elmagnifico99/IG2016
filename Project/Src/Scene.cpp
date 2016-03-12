#include <Scene.hpp>
#include <iostream>

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

/*explicit*/ Node* Scene::GetRootNode()
{
	return m_rootNode;
}

/*explicit*/ void Scene::Render()
{
	m_rootNode->Render();
}

/*virtual*/ void Scene::save()
{

}

/*virtual*/ void Scene::load(const char* fileName)
{

}