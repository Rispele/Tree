#include "treeitem.h"

template<class type>
TreeItem<type>::TreeItem(type x)
{
	m_value = x;
	m_child = vector<TreeItem *>(0);
}

template<class type>
void TreeItem<type>::addChild(TreeItem *item)
{
	m_child.push_back(item);
}

template<class type>
void TreeItem<type>::delChild(int index)
{
	m_child.erase(m_child.begin() + index);
}

template<class type>
void TreeItem<type>::absDelChild(int index)
{
	TreeItem<type> *l = m_child[index];
	m_child.erase(m_child.begin() + index);
	delete[] l;
}

template<class type>
TreeItem<type> *TreeItem<type>::parent() const
{
	return m_parent;
}

template<class type>
void TreeItem<type>::setParent(TreeItem<type> *parent)
{
	m_parent = parent;
}

template<class type>
depthVar TreeItem<type>::depth() const
{
	return m_depth;
}

template<class type>
void TreeItem<type>::setDepth(const depthVar &depth)
{
	m_depth = depth;
}

template<class type>
type TreeItem<type>::value() const
{
	return m_value;
}

template<class type>
void TreeItem<type>::setValue(const type &value)
{
	m_value = value;
}

template<class type>
vector<TreeItem<type> *> TreeItem<type>::child() const
{
	return m_child;
}
