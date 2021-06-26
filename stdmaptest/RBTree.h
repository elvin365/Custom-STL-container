#pragma once
//RBTree.h
#include"RBTNode.h"
#include <iomanip>
using namespace std;

template<class T,class R>
class  RBTree
{
public:
	RBTree();
	~RBTree();
	RBTNode<T, R>* f_begin();
	RBTNode<T, R>* l_end();
	RBTNode<T, R>* Inc(RBTNode<T, R>*);
	RBTNode<T, R>* Dec(RBTNode<T, R>*);
	const int Size() const;
	//template<class R>
	void insert(T key,R info);    // Insert node, key is the key value, external interface
	void remove(T key); // Delete the node of the key
	//template<class R>
	RBTNode<T,R>* search(T key);

	//----------------------------- operator []
	//template<class R>
	R& searchOperator(T key);//так же дл€ оператора []
	//template<class R>
	RBTNode<T,R>& searchOperatorKV(RBTNode<T,R>*node, T key) ;// дл€ оператора []
	//------------------------------operator []

	void print();
	void preOrder();    // Pre - order traversal Print red black tree
	void inOrder();    //Intermediate traversal
	void postOrder();    // Post - order traversal

	//конструктор копировани€
	RBTree(const RBTree<T,R>& source)  
	{
		root=source.root;
	}

private:
	//template<class R>
	void leftRotate(RBTNode<T,R>* &root, RBTNode<T,R>* x);// left-handed
	//template<class R>
	void rightRotate(RBTNode<T,R>* &root, RBTNode<T,R>* y);// right handed
	//template<class R>
	void insert(RBTNode<T,R>* &root, RBTNode<T,R>* node);// insert node, internal interface
	//template<class R>
	void InsertFixUp(RBTNode<T,R>* &root, RBTNode<T,R>* node);
	//template<class R>
	void destory(RBTNode<T,R>* &node);
	//template<class R>
	void remove(RBTNode<T,R>*& root, RBTNode<T,R>*node); // Delete the node as KEY
	//template<class R>
	void removeFixUp(RBTNode<T,R>* &root, RBTNode<T,R>* node, RBTNode<T,R>*parent);
	//template<class R>
	RBTNode<T,R>* search(RBTNode<T,R>*node, T key) const;
	//template<class R>
	void print(RBTNode<T,R>* node)const;
	//template<class R>
	void preOrder(RBTNode<T,R>* tree)const;
	//template<class R>
	void inOrder(RBTNode<T,R>* tree)const;
	//template<class R>
	void postOrder(RBTNode<T,R>* tree)const;
private:
	//template<class R>
	RBTNode<T,R>*root;
	int size;
};

template<class T,class R> //Constructor
 RBTree<T,R>::RBTree() :root(NULL) {
	root = nullptr;
	size = 0;
}
template<class T,class R>		//Destructor
RBTree<T,R>::~RBTree() {
	size = 0;
	//destory(root);
}

template<class T, class R>
RBTNode<T, R>* RBTree<T, R>::f_begin()
{
	RBTNode<T, R>* current = root;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
	{
		current = current->left;
	}
	return(current);
	// TODO: вставьте здесь оператор return
}

template<class T, class R>
RBTNode<T, R>* RBTree<T, R>::l_end()
{
	RBTNode<T, R>* current = root;

	/* loop down to find the leftmost leaf */
	while (current->right != NULL)
	{
		current = current->right;
	}
	return(current);
	// TODO: вставьте здесь оператор return
}

template<class T, class R>
 RBTNode<T, R>* RBTree<T, R>::Inc(RBTNode<T, R>* current)
{
	 if (current->right != NULL)
	 {
		 return (current->right);
	 }
	 
	//return NULL;
}

 template<class T, class R>
 RBTNode<T, R>* RBTree<T, R>::Dec(RBTNode<T, R>* current)
 {
	 
	 if (current->left != NULL)
	 {
		 return current->left;
	 }
	 else if (current->right != NULL)
	 {
		 return current->right;
	 }
	 
 }

 template<class T, class R>
 const int RBTree<T, R>::Size() const
 {
	 return size;
 }


template<class T,class R>		//Left
void RBTree<T,R>::leftRotate(RBTNode<T,R>* &root, RBTNode<T,R>* x) {
	RBTNode<T,R>*y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
};
template<class T,class R>		//right spin
void RBTree<T,R>::rightRotate(RBTNode<T,R>*&root, RBTNode<T,R>*y) {
	RBTNode<T,R>*x = y->left;
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;
	if (y->parent == NULL)
		root = x;
	else {
		if (y == y->parent->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}
	x->right = y;
	y->parent = x;
};
template<class T,class R>		//insert
void RBTree<T,R>::insert(T key,R info)
{
	RBTNode<T,R>*z = new RBTNode<T,R>(key, Red, NULL, NULL, NULL,info);
	++size;
	insert(root, z);
};
template<class T,class R>
void RBTree<T,R>::insert(RBTNode<T,R>* &root, RBTNode<T,R>* node)
{
	RBTNode<T,R> *x = root;
	RBTNode<T,R> *y = NULL;
	while (x != NULL)
	{
		y = x;//происходит каждый раз дл€ установлени€ родител€ вставл€емго эелемента,углубл€мс€ в дерево
		if (node->Element.first > x->Element.first)
			x = x->right;//находим самого правого
		else
			x = x->left;
	}
	node->parent = y;
	if (y != NULL)
	{
		if (node->Element.first > y->Element.first)//устанавливаем потомка справа или слева от его толбько что найденного родител€ 
			y->right = node;
		else
			y->left = node;
	}
	else
		root = node;
	node->color = Red;
	InsertFixUp(root, node);
};
template<class T,class R>
void RBTree<T,R>::InsertFixUp(RBTNode<T,R>* &root, RBTNode<T,R>* node)
{
	RBTNode<T,R>*parent;
	parent = node->parent;
	while (node != RBTree::root  && parent->color == Red)
	{
		RBTNode<T,R>*gparent = parent->parent;
		if (gparent->left == parent)
		{
			RBTNode<T,R>*uncle = gparent->right;
			if (uncle != NULL && uncle->color == Red)
			{
				parent->color = Black;//1
				uncle->color = Black;//1
				gparent->color = Red;//1
				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->right == node)
				{
					leftRotate(root, parent);//2
					swap(node, parent);
				}
				rightRotate(root, gparent);//3
				gparent->color = Red;//3
				parent->color = Black;//3
				break;
			}
		}
		else
		{
			RBTNode<T,R>*uncle = gparent->left;
			if (uncle != NULL && uncle->color == Red)
			{
				gparent->color = Red;
				parent->color = Black;
				uncle->color = Black;

				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->left == node)
				{
					rightRotate(root, parent);
					swap(parent, node);
				}
				leftRotate(root, gparent);
				parent->color = Black;
				gparent->color = Red;
				break;
			}
		}
	}
	root->color = Black;
}
template<class T,class R>
//Destroy the red black tree


void RBTree<T,R>::destory(RBTNode<T,R>* &node)
{
	if (node == NULL)
		return;
	destory(node->left);
	destory(node->right);
	delete node;
	node = nullptr;
}
template<class T,class R>
void RBTree<T,R>::remove(T key)
{
	
	RBTNode<T,R>*deletenode = search(root, key);
	if (deletenode != NULL)
	{
		remove(root, deletenode);
		--size;
	}
		
}
template<class T,class R>
void RBTree<T,R>::remove(RBTNode<T,R>*&root, RBTNode<T,R>*node)
{
	RBTNode<T,R> *child, *parent;
	RBTColor color;
	//The node left and right of the deleted node is not empty (not the leaf node)
	if (node->left != NULL && node->right != NULL)
	{
		RBTNode<T,R> *replace = node;
		// Find the successor node(the lowest node of the right subtree of the current node)
			replace = node->right;
		while (replace->left != NULL)
		{
			replace = replace->left;
		}
		//The deleted node is not the root node.
		if (node->parent != NULL)
		{
			if (node->parent->left == node)
				node->parent->left = replace;
			else
				node->parent->right = replace;
		}
		//root node situation
		else
			root = replace;
		//child is the right node of the replacement node, which is the node that needs subsequent adjustment.
		//Because replace is a successor node, it is impossible for him to have a left child.
		//The same reason that the precursor node cannot have the right child node
		child = replace->right;
		parent = replace->parent;
		color = replace->color;

		// The node is replaced by the parent node of the repalce
			if (parent == node)
				parent = replace;
			else
			{
				//Children's node exists
				if (child != NULL)
					child->parent = parent;
				parent->left = child;

				replace->right = node->right;
				node->right->parent = replace;
			}
		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;
		if (color == Black)
			removeFixUp(root, child, parent);

		delete node;
		return;
	}
	// When the deleted node has only the left(right) node is empty, find the child node of the deleted node
		if (node->left != NULL)
			child = node->left;
		else
			child = node->right;

	parent = node->parent;
	color = node->color;
	if (child)
	{
		child->parent = parent;
	}
	//The deleted node is not the root node
	if (parent)
	{
		if (node == parent->left)
			parent->left = child;
		else
			parent->right = child;
	}
	//The deleted node is the root node
	else
		RBTree::root = child;

	if (color == Black)
	{
		removeFixUp(root, child, parent);
	}
	delete node;

}
template<class T,class R>
void RBTree<T,R>::removeFixUp(RBTNode<T,R>* &root, RBTNode<T,R>* node, RBTNode<T,R>*parent)
{
	RBTNode<T,R>*othernode;
	while ((!node) || node->color == Black && node != RBTree::root)
	{
		if (parent->left == node)
		{
			othernode = parent->right;
			if (othernode->color == Red)
			{
				othernode->color = Black;//1
				parent->color = Red;//1
				leftRotate(root, parent);//1
				othernode = parent->right;//1
			}
			else
			{
				if (!(othernode->right) || othernode->right->color == Black)
				{
					othernode->left->color = Black;//3
					othernode->color = Red;//3
					rightRotate(root, othernode);//3
					othernode = parent->right;//3
				}
				othernode->color = parent->color;//4
				parent->color = Black;//4
				othernode->right->color = Black;//4
				leftRotate(root, parent);//4
				node = root;//4
				break;
			}
		}
		else
		{
			othernode = parent->left;
			if (othernode->color == Red)
			{
				othernode->color = Black;
				parent->color = Red;
				rightRotate(root, parent);
				othernode = parent->left;
			}
			if ((!othernode->left || othernode->left->color == Black) && (!othernode->right || othernode->right->color == Black))
			{
				othernode->color = Red;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if (!(othernode->left) || othernode->left->color == Black)
				{
					othernode->right->color = Black;
					othernode->color = Red;
					leftRotate(root, othernode);
					othernode = parent->left;
				}
				othernode->color = parent->color;
				parent->color = Black;
				othernode->left->color = Black;
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		node->color = Black;
}

template<class T,class R>
RBTNode<T,R>* RBTree<T,R>::search(T key)
{
	return search(root, key);
}
template<class T,class R>
RBTNode<T,R>* RBTree<T,R>::search(RBTNode<T,R>*node, T key) const
{
	if (node == NULL || node->Element.first == key)
		return node;
	else
		if (key > node->Element.first)
			return search(node->right, key);
		else
			return search(node->left, key);
}
template<class T,class R>		// Output binary tree details
void RBTree<T,R>::print() {
	if (root == NULL)
		std::cout << "empty RBtree\n";
	else
		print(root);
}
template<class T,class R>
void RBTree<T,R>::print(RBTNode<T,R>* node)const {
	if (node == NULL)
		return;
	if (node->parent == NULL)
		std::cout << node->Element.first << "(" << node->color << ") is root" << endl;
	else if (node->parent->left == node)
	{
		std::cout << node->Element.first << "(" << node->color << ") is " << node->parent->key << "'s " << "left child" << endl;
	}
	else
	{
		std::cout << node->Element.first << "(" << node->color << ") is " << node->parent->key << "'s " << "right child" << endl;
	}
	print(node->left);
	print(node->right);
}
template<class T,class R>		// Pre - order traversal RB tree
void RBTree<T,R>::preOrder() {
	if (root == NULL)
		std::cout << "empty RBtree\n";
	else
		preOrder(root);
};
template<class T,class R>
void RBTree<T,R>::preOrder(RBTNode<T,R>* tree)const {
	if (tree != NULL) {
		std::cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
template<class T,class R >		// Traverse RB tree
void RBTree<T,R>::inOrder() {
	if (root == NULL)
		std::cout << "empty RBtree\n";
	else
		inOrder(root);
};
template<class T,class R>
void RBTree<T,R>::inOrder(RBTNode<T,R>* tree)const {
	if (tree != NULL) {
		inOrder(tree->left);
		std::cout << tree->key << " ";
		inOrder(tree->right);
	}
}
template<class T,class R>     // Traverse RB tree
void RBTree<T,R>::postOrder() {
	if (root == NULL)
		std::cout << "empty RBtree\n";
	else
		postOrder(root);
};
template<class T,class R>
void RBTree<T,R>::postOrder(RBTNode<T,R>* tree)const {
	if (tree != NULL) {
		postOrder(tree->left);
		postOrder(tree->right);
		std::cout << tree->key << " ";
	}
}

template<class T,class R>
R& RBTree<T,R>::searchOperator(T key)
{
	return searchOperatorKV(root, key).Element.second;
}
template<class T,class R>

RBTNode<T,R>& RBTree<T,R>::searchOperatorKV(RBTNode<T,R>*node, T key) 
{
	/*if (node == NULL || node->key == key)
		return node;*/
	if (node == NULL)
	{
		//создадим новый экземпл€р ноды 
		insert(key,"Empty");
		return *search(key);// раз вставил, то найди где он теперь
		/*if (node->parent->left != NULL)
		{
			return node->parent->left;//
		}
		else
		{
			return node->parent->right;

		}*/
		
	}
	if (node->Element.first == key)
	{
		return *node;
	}
	else
		if (key > node->Element.first)
			return (searchOperatorKV(node->right, key));
		else
			return (searchOperatorKV(node->left, key));
}