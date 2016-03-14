#ifndef __NODE_HPP
#define __NODE_HPP

#include <vector>
#include <string>
#include <Vector.hpp>

class Leaf;

class Node
{

public:

	explicit				Node				(void);
	virtual					~Node				(void);
  
	virtual unsigned int	GetChildNodeCount	(void) const;
	virtual Node*			GetChildNode		(unsigned int index);

	virtual unsigned int	GetChildLeafCount	(void) const;
	virtual Leaf*			GetChildLeaf		(unsigned int index);

	virtual void			ApplyTransformation	(void) = 0;
	virtual void			Render				(void);
  
	virtual void			Add					(Node* node);
	virtual void			Add					(Leaf* leaf);
	virtual void			Remove				(Node* node);
	virtual void			Remove				(Leaf* leaf);

	virtual void			ClearChildrenNodes	(void);
	virtual void			ClearChildrenLeafs	(void);
	virtual void			ClearAllChildren	(void);

	virtual Node*			GetParent			(void) const;
	virtual void			SetParent			(Node* parent);

	virtual void			SetEnabled			(bool state);
	virtual bool			IsEnabled			(void) const;

	virtual void			Dump				(std::string tab, unsigned int tabCount) = 0;
	virtual void			DumpChildren		(std::string tab, unsigned int tabCount);

protected:

	std::vector<Node*>	m_nodeChildren;
	std::vector<Leaf*>	m_leafChildren;

	Node*				m_parent;
	bool				m_enabled;

};

#endif // __NODE_HPP