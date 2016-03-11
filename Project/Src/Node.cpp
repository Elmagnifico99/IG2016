#include <Node.hpp>
#include <Leaf.hpp>
#include <GL/gl.h>

/*explicit*/ Node::Node()
	: m_nodeChildren()
	, m_leafChildren()
	, m_parent(nullptr)
{

}

/*virtual*/ Node::~Node()
{

}

/*virtual*/ unsigned int Node::GetChildNodeCount() const
{
	return m_nodeChildren.size();
}

/*virtual*/ Node* Node::GetChildNode(int index)
{
	if(index >= 0 && index < m_nodeChildren.size())
	{
		return m_nodeChildren[index];
	}
	return nullptr;
}

/*virtual*/ unsigned int Node::GetChildLeafCount() const
{
	return m_leafChildren.size();
}

/*virtual*/ Leaf* Node::GetChildLeaf(int index)
{
	if(index >= 0 && index < m_leafChildren.size())
	{
		return m_leafChildren[index];
	}
	return nullptr;
}

/*virtual*/ void Node::Render()
{
	for(std::vector<Leaf*>::iterator it = m_leafChildren.begin(); it != m_leafChildren.end(); ++it)
	{
		(*it)->Render();
	}
	for(std::vector<Node*>::iterator it = m_nodeChildren.begin(); it != m_nodeChildren.end(); ++it)
	{
		(*it)->Render();
	}
}

/*virtual*/ void Node::Add(Node* node)
{
	for(std::vector<Node*>::iterator it = m_nodeChildren.begin(); it != m_nodeChildren.end(); ++it)
	{
		if(*it == node)
		{
			return;
		}
	}
	m_nodeChildren.push_back(node);
	if(nullptr != node->m_parent)
	{
		node->m_parent->Remove(node);
	}
	node->m_parent = this;
}

/*virtual*/ void Node::Add(Leaf* leaf)
{
	for(std::vector<Leaf*>::iterator it = m_leafChildren.begin(); it != m_leafChildren.end(); ++it)
	{
		if(*it == leaf)
		{
			return;
		}
	}
	m_leafChildren.push_back(leaf);
	if(nullptr != leaf->GetParent())
	{
		leaf->GetParent()->Remove(leaf);
	}
	leaf->SetParent(this);
}

/*virtual*/ void Node::Remove(Node* node)
{
	for(std::vector<Node*>::iterator it = m_nodeChildren.begin(); it != m_nodeChildren.end(); ++it)
	{
		if(*it == node)
		{
			m_nodeChildren.erase(it);
			return;
		}
	}
}

/*virtual*/ void Node::Remove(Leaf* leaf)
{
	for(std::vector<Leaf*>::iterator it = m_leafChildren.begin(); it != m_leafChildren.end(); ++it)
	{
		if(*it == leaf)
		{
			m_leafChildren.erase(it);
			return;
		}
	}
}

/*virtual*/ void Node::ClearChildrenNodes()
{
	// Iterate through children nodes
	for(std::vector<Node*>::iterator it = m_nodeChildren.begin(); it != m_nodeChildren.end(); ++it)
	{
		// Add all sub-node nodes
		for(std::vector<Node*>::iterator it2 = (*it)->m_nodeChildren.begin(); it2 != (*it)->m_nodeChildren.end(); ++it2)
		{
			Add(*it2);
		}
		// Add all sub-node leafs
		for(std::vector<Leaf*>::iterator it2 = (*it)->m_leafChildren.begin(); it2 != (*it)->m_leafChildren.end(); ++it2)
		{
			Add(*it2);
		}
	}
	// Remove all sub-nodes;
	while(0 != m_nodeChildren.size())
	{
		delete m_nodeChildren[m_nodeChildren.size() - 1];
		m_nodeChildren.pop_back();
	}
}

/*virtual*/ void Node::ClearChildrenLeafs()
{
	// Remove all leafs
	while(0 != m_leafChildren.size())
	{
		delete m_leafChildren[m_leafChildren.size() - 1];
		m_leafChildren.pop_back();
	}
}

/*virtual*/ void Node::ClearAllChildren()
{
	ClearChildrenNodes();
	ClearChildrenLeafs();
}

/*virtual*/ Node* Node::GetParent() const
{
	return m_parent;
}

/*virtual*/ void Node::SetParent(Node* parent)
{
	m_parent = parent;
}

/*virtual*/ void Node::DumpChildren(std::string tab, unsigned int tabCount)
{
	unsigned int nextTabCount = tabCount + 1;
	for(std::vector<Leaf*>::iterator it = m_leafChildren.begin(); it != m_leafChildren.end(); ++it)
	{
		(*it)->Dump(tab, nextTabCount);
	}
	for(std::vector<Node*>::iterator it = m_nodeChildren.begin(); it != m_nodeChildren.end(); ++it)
	{
		(*it)->Dump(tab, nextTabCount);
	}
}
