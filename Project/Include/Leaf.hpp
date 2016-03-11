#ifndef __LEAF_HPP
#define __LEAF_HPP

#include <Node.hpp>

class Leaf
{

public:

	explicit		Leaf		(void);
	virtual			~Leaf		(void);

	virtual void	Render		(void) = 0;

	virtual Node*	GetParent	(void) const;
	virtual void	SetParent	(Node* parent);

	virtual void	Dump		(std::string tab, unsigned int tabCount) = 0;

protected:

	Node*			m_parent;

};

#include "Leaf.inl"

#endif // __LEAF_HPP