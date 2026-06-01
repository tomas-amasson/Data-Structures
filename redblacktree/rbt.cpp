#include "rbt.h"

RBTnode *RBT::rotate_left_right(RBTnode *z)
{
	rotate_left(z->left);
	RBTnode *w = rotate_right(z);
	return w;
}

RBTnode *RBT::rotate_right_left(RBTnode *z)
{
	rotate_right(z->right);
	RBTnode *w = rotate_left(z);
	return w;
}

RBTnode *RBT::rotate_left(RBTnode *x)
{
	RBTnode *y = x->right;
	RBTnode *b = y->left;

	x->right 	= b;
	b->father 	= x;
	y->left 	= x;
	y->father	= x->father;

	if (x == x->father->left)
		x->father->left  = y;
	else
		x->father->right = y;
	return y;
}

RBTnode *RBT::rotate_right(RBTnode *y)
{

	RBTnode *x = y->left;
	RBTnode *b = x->right;

	y->left 	= b;
	b->father 	= y;
	x->right 	= y;
	x->father 	= y->father;

	if (y == y->father->left)
		y->father->left  = x;
	else
		y->father->right = x;

	y->father = x;
	return x;
}


void RBT::insert_fix(RBTnode *z)
{
	RBTnode *y;

	while (z->father->color == RED)
	{
		if (z->father == z->father->father->left)
		{
			y = z->father->father->right;
			if (y->color == RED)
			{
				z->father->color = BLACK;
				y->color = BLACK;
				z->father->father->color = RED;
				z = z->father->father;
			}		
			else 
			{
				if (z == z->father->right)
				{
					z->father->color = BLACK;
					z = rotate_left_right(z->father->father);
				}
				else
				{
					z->color = BLACK;
					z = rotate_right(z->father->father);
				}
			}
		}
		else
		{
			y = z->father->father->left;
			if (y->color == RED)
			{
				z->father->color = BLACK;
				y->color = BLACK;
				z->father->father->color = RED;
				z = z->father->father;
			}
			else
			{
				if (z == z->father->left)
				{
					z->father->color = BLACK;
					z = rotate_right_left(z->father->father);
				}
				else
				{
					z->color = BLACK;
					z = rotate_left(z->father->father);
				}
			}
		}
	}
	this->root->color = BLACK;
}

void RBT::transplant(RBTnode *u, RBTnode *v)
{
	if (u->father == nullptr)
	{
		this->root = v;
	}
	else if (u == u->father->left)
	{
		u->father->left = v;
	}
	else
	{
		u->father->right = v;
	}
	v->father = u->father;
}

void RBT::RBTdelete(RBTnode *z)
{
	RBTnode *y = z, *x;
	unsigned int ycolor = y->color;

	if (z->left == nullptr)
	{
		x = z->right;
		transplant(z, x);
	}
	
	else if (z->right == nullptr)
	{
		x = z->left;
		transplant(z, x);
	}

	else 
	{
		y = tree_minimum(z->right);
		ycolor = y->color;
		x = y->right;

		if (y == z->right)
		{
			x->father = y;
		}
		else
		{
			transplant(y, x);
			y->right = z->right;
			y->right->father = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->father = y;
	}
	if (ycolor == BLACK)
	{
		RBTdelete_fix(x);
	}
}

RBTnode *RBT::tree_minimum(RBTnode *x)
{
	RBTnode *tracker = x;
	while (tracker->left != nullptr)
	{
		tracker = tracker->left;
	}
	return tracker;
}

void RBT::RBTdelete_fix(RBTnode *x)
{
	RBTnode *w;
	while (x != this->root && x->color == BLACK)
	{
		if (x == x->father->left)
		{
			w = x->father->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->father->color = RED;
				w = x->father->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->father;
			}
			else 
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					rotate_right(w);
					w = x->father->right;
				}
				w->color = x->father->color;
				w->father->color = BLACK;
				x->right->color = BLACK;
				rotate_left(x->father);

				x = this->root;
			}
		}
		else 
		{
			w = x->father->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->father->color = RED;
				w = x->father->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->father;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					rotate_left(w);
					w = x->father->left;	
				}
				w->color = x->father->color;
				w->father->color = BLACK;
				x->left->color = BLACK;
				rotate_right(x->father);

				x = this->root;
			}	
		}	
	}
	x->color = BLACK;
}
