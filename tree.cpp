#include "tree.h"

template<class type>
Tree<type>::Tree(vector<TreeItem<type> *> *elems, TreeItem<type> *root)
{
	buildTree(root, root, 0);
}

template<class type>
void Tree<type>::buildTree(TreeItem<type> *root, TreeItem<type> *current, int depth)
{
	int a = current->value();
	vector<TreeItem<type> *> child = current->child();
	unsigned int sz = child.size();

	current->setDepth(depth);
	current->setParent(root);
	for(int i = 0; i < sz; i++){
		if(root == child[i]){
			current->delChild(i);
			continue;
		}
		buildTree(current, child[i], ++depth);
	}
}
