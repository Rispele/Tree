#ifndef TREEITEM_H
#define TREEITEM_H

#include <vector>
using namespace std;

typedef unsigned int depthVar;

template <class type>
class TreeItem
{
public:
	TreeItem(type);

	void addChild(TreeItem *);
	void delChild(int index);
	void absDelChild(int index);
	vector<TreeItem *> child() const;

	TreeItem *parent() const;
	void setParent(TreeItem *parent);

	depthVar depth() const;
	void setDepth(const depthVar &depth);

	type value() const;
	void setValue(const type &value);

private:
	vector<TreeItem*> m_child;
	TreeItem *m_parent = nullptr;

	type m_value;
	depthVar m_depth;

};

#endif // TREEITEM_H
