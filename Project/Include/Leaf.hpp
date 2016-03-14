#ifndef __LEAF_HPP
#define __LEAF_HPP

#include <Config.hpp>

#include <Node.hpp>
#include <Light.hpp>

class Leaf
{

public:

	explicit		Leaf		(void);
	virtual			~Leaf		(void);

	virtual void	Render		(void) = 0;

	virtual Node*	GetParent	(void) const;
	virtual void	SetParent	(Node* parent);

	virtual void	SetEnabled	(bool state);
	virtual bool	IsEnabled	(void) const;

	virtual void	Dump		(std::string tab, unsigned int tabCount) = 0;

protected:

	Node*			m_parent;
	bool			m_enabled;

};

class LightLeaf : public Leaf
{

public:

	virtual Light*	GetLight(void) const;
	virtual void	SetLight(Light* light);

protected:

	Light* m_light;

};

class CameraLeaf : public Leaf
{

};

#ifndef NO_INLINE
#include "Leaf.inl"
#endif // NO_INLINE

#endif // __LEAF_HPP