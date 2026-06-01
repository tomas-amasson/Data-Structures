#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#define RED 0 
#define BLACK 1

typedef struct RBTnode {
unsigned int 	color : 1;
int 		key;

RBTnode		*father;
RBTnode 	*right;
RBTnode 	*left;
} RBTnode;


class RBT
{
	private:
		RBTnode *root;

	public:
		RBTnode *rotate_right(RBTnode *y); // O(1)
		RBTnode *rotate_left(RBTnode *x); // O(1)

		RBTnode *rotate_right_left(RBTnode *z); // O(1)
		RBTnode *rotate_left_right(RBTnode *z); // O(1)

		void insert_fix(RBTnode *z); // O(logn)
		
		RBTnode *tree_minimum(RBTnode *x);
		void transplant(RBTnode *u, RBTnode *v); // O(1)
		void RBTdelete(RBTnode *z);
		void RBTdelete_fix(RBTnode *x);
};


#endif
