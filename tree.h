#ifndef TREE_H
#define TREE_H

#include <vector>
#include <D:\QT Projects\Libraries\Tree\Tree\treeitem.h>

using namespace std;

template <class type>
class Tree
{
public:
	Tree(vector<TreeItem<type>*> *elems, TreeItem<type> *root);

	TreeItem<type> *lca(TreeItem<type> *item1, TreeItem<type> *item2);
private:
	void buildTree(TreeItem<type> *root, TreeItem<type> *child, int depth = 0);

	vector<TreeItem<type> *> *m_items;

};

#endif // TREE_H