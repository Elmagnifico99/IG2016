#include <Leaf.hpp>

/*explicit*/ inline Leaf::Leaf()
	: m_parent(nullptr)
{

}

/*virtual*/ inline Leaf::~Leaf()
{

}

/*virtual*/ inline Node* Leaf::GetParent() const
{
	return m_parent;
}

/*virtual*/ inline void Leaf::SetParent(Node* parent)
{
	m_parent = parent;
}
