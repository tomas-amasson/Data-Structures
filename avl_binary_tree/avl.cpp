#include "avl.h"
#include <stdlib.h>

AVLnode *AVL::rotate_left(AVLnode *x)
{
	AVLnode *y = x->right;
	AVLnode *b = y->left;

	x->right 	= b;
	b->father 	= x;
	y->left 	= x;
	y->father	= x->father;

	if (x == x->father->left)
		x->father->left  = y;
	else
		x->father->right = y;

	x->father = y;
	x->height = 1 + max(node_height(*x->left), node_height(*x->right));
	y->height = 1 + max(node_height(*y->left), node_height(*y->right));

	return y;
}

AVLnode *AVL::rotate_right(AVLnode *y)
{
	AVLnode *x = y->left;
	AVLnode *b = x->right;

	y->left 	= b;
	b->father 	= y;
	x->right 	= y;
	x->father 	= y->father;

	if (y == y->father->left)
		y->father->left  = x;
	else
		y->father->right = x;

	y->father = x;
	y->height = 1 + max(node_height(*y->left), node_height(*y->right));
	x->height = 1 + max(node_height(*x->left), node_height(*x->right));

	return x;

}

AVLnode *AVL::rotate_left_right(AVLnode *z)
{
	rotate_left(z->left);
	AVLnode *w = rotate_right(z);
	return w;
}

AVLnode *AVL::rotate_right_left(AVLnode *z)
{
	rotate_right(z->right);
	AVLnode *w = rotate_left(z);
	return w;
}

AVLnode *AVL::search(AVLnode *root, int key)
{
	if (root == nullptr || root->key == key)
			return root;
	if (root->key > key)
		return AVL::search(root->left, key);
	else
		return AVL::search(root->right, key);
}

AVLnode *AVL::insert_recursive(AVLnode *node, int key)
{
	if (node == nullptr)
	{
		node 		= (AVLnode *) malloc(sizeof(AVLnode));
		node->key 	= key;
		node->height 	= 0;
		return node;
	}

	if (key < node->key)
		node->left = AVL::insert_recursive(node->left, key);
	else if (key > node->key)
		node->right = AVL::insert_recursive(node->right, key);
	else 
		return node;

	// Volta da recursão
	node->height = 1 + max(node_height(*node->left), node_height(*node->right));
	int b = AVL::balance(*node);

	if (b > 1 && key < node->left->key) 	// Caso A
		return rotate_right(node);

	if (b > 1 && key > node->left->key) 	// Caso B
		return rotate_left_right(node);

	if (b < 1 && key < node->right->key) 	// Caso C
		return rotate_left(node);

	if (b < 1 && key > node->right->key) 	// Caso D
		return rotate_right_left(node);

	return node;
}

AVLnode *AVL::remove(AVLnode *node, int key)
{

	// TOP DOWN
	if (node == nullptr)
		return node;
	
	if (key < node->key)
		node->left = remove(node->left, key);
	else if (key > node->key)
		node->right = remove(node->right, key);
	else 
	{
		if (node->left == nullptr)
			return node->right;
		if (node->right == nullptr)
			return node->left;
		
		AVLnode *sucessor = tree_minimum(node->right);
		node->key = sucessor->key;

		node->right = remove(node->right, sucessor->key);
		delete sucessor;
	}

	// BOTTOM UP
	node->height = 1 + max(node_height(*node->left), node_height(*node->right));
	int b = balance(node);

	if (b > 1 && balance(node->left) >= 0)
		return rotate_right(node);

	if (b > 1 && balance(node->left) < 0)
		return rotate_left_right(node);

	if (b < -1 && balance(node->right) <= 0)
		return rotate_left(node->node);
	
	if (b < -1 && balance(node->right) > 0 )
		return rotate_right_left(node);

	return node;
}
AVLnode *AVL::tree_minimum(AVLnode *root)
{
	AVLnode *tracker = root;
	while (tracker->left != nullptr)
		tracker = tracker->left;

	return tracker;
}	

AVLnode *AVL::tree_maximum(AVLnode *root)
{
	AVLnode *tracker = root;
	while (tracker->right != nullptr)
		tracker = tracker->right;

	return tracker;
}

AVLnode AVL::tree_sucessor(AVLnode *x)
{
	return tree_maximum(x);
}

int AVL::balance(AVLnode &z)
{
	return (node_height(*z.left) - node_height(*z.right)); 
}

int AVL::node_height(AVLnode a)
{
	if (&a == nullptr)
		return -1;
	return a.height;
}

int AVL::max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
