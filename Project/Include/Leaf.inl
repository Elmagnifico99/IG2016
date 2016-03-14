#include <Leaf.hpp>

/*explicit*/ INLINE Leaf::Leaf()
	: m_parent(nullptr)
{

}

/*virtual*/ INLINE Leaf::~Leaf()
{

}

/*virtual*/ INLINE Node* Leaf::GetParent() const
{
	return m_parent;
}

/*virtual*/ INLINE void Leaf::SetParent(Node* parent)
{
	m_parent = parent;
}

/*virtual*/ void Leaf::SetEnabled(bool state)
{
	m_enabled = state;
}

/*virtual*/ bool Leaf::IsEnabled() const
{
	return m_enabled;
}

/*virtual*/ Light* LightLeaf::GetLight() const
{
	return m_light;
}

/*virtual*/ void LightLeaf::SetLight(Light* light)
{
	m_light = light;
}
