#include "tree.h"

template<class type>
Tree<type>::Tree(vector<TreeItem<type> *> *elems, TreeItem<type> *root)
{
	m_items = elems;
	buildTree(root, root, 1);
}

template<class type>
TreeItem<type> *Tree<type>::lca(TreeItem<type> *item1, TreeItem<type> *item2)
{
	TreeItem<type> *botItem, *topItem;

	if(item1->depth() > item2->depth()){
		topItem = item2;
		botItem = item1;
	}
	else{
		topItem = item1;
		botItem = item2;
	}

	int depth = abs(int(item1->depth() - item2->depth()));
	for(int i = 0; i < depth; i++){
		botItem = botItem->parent();
	}

	while(botItem != topItem){
		botItem = botItem->parent();
		topItem = topItem->parent();
	}

	return topItem;
}

template<class type>
void Tree<type>::buildTree(TreeItem<type> *root, TreeItem<type> *current, int depth)
{
	vector<TreeItem<type> *> child = current->child();
	size_t sz = child.size();

	current->setDepth(depth);
	current->setParent(root);
	for(size_t i = 0; i < sz; i++){
		if(root == child[i]){
			current->delChild(i);
			continue;
		}
		buildTree(current, child[i], depth + 1);
	}
}
