#ifndef AVL_SEARCH_TREE_H
#define AVL_SEARCH_TREE_H

/* Um tipo de árvore binária de busca (bst)

BALANCED BST AVL:	Altura do node = -1 <= folha à esquerda - folha à direita <= 1

DESBALANCEAMENTO:	INSERÇÃO OU REMOÇÃO

REBALANCEAMENTO:	ROTAÇÃO LEFT OU RIGHT

BUSCA, INSERÇÃO, DELEÇÃO = O(kn), onde k = altura da árvore.




*/



typedef struct AVLnode{

// Chave do nó	
int 	key;
// Altura do nó, raiz com altura máxima, folha com altura mínima
int 	height;
// Fator de balanceamento balance = left.height - right.height
int 	balance; 

AVLnode *father;
AVLnode *right;
AVLnode *left;

} AVLnode;

class AVL 
{
	private:
		AVLnode *root;
		int 	 size;
	public:
	
	// Mudam a raiz relativa do node.
	AVLnode *rotate_left(AVLnode *x);  
	// node.balanced < -1
	
	AVLnode *rotate_right(AVLnode *y); 
	// node.balanced >  1
		
	AVLnode *rotate_left_right(AVLnode *z);
	AVLnode *rotate_right_left(AVLnode *z);
	
	AVLnode	*insert_recursive(AVLnode *node, int key); 
	// x: nó inserido, z: 1° nó desbalanceado bottom-up a partir de x.
	/* INSERÇÃO 	= TopDown + BottomUp    +  Rotations
	 	    	  (busca)   (busca unbal)  (balance)
	 		  (log(n))  (log(n))       O(1)
	 
	   T(n) = O(log(n))
	 */

	AVLnode *search(AVLnode *root, int key);
	/* Para toda árvore avl, x.height = {-1, 0, 1}
	 	ou seja, | x.left.height - x.right.height | <= 1
	 
	 	a) left.height = right.height -> numero de nós iguais. =  busca binária
	 	b) left.height +- 1 = right.height (problema vai de n para 2/3n e assim por diante (recorrencia)), ainda log(n)
	 */


	AVLnode *remove(AVLnode *node, int key);
	/*
	 
		COMPLEXIDADE = Top-Down	+ Sucessor + Bottom-Up + Rotações
			       	log(n)  +  log(n)  +   log(n)  +   O(1)
		T(n) = 3log(n) + 1
		O(log(n))

		CASO w não tenha filhos && w à esquerda de z:
		° Retira-se w
		° Se z.height >= 0, Rotação à direita em z
		° Se z.height < 0, Rotação esquerda-direita em z	
		
		CASO w não tenha filhos && w à direita de z:
		° Retira-se w
		° Se z.height <= 0, Rotação à esquerda em z
		° Se z.height > 0, Rotação direita-esquerda em z


	 	CASO w tenha 1 filhos:
	 	° Encontrar o sucessor S de w
		° copiar chave de S para w
		° remover S
		° caminho bottom-up até z;


	 */

	AVLnode *tree_minimum(AVLnode *root);
	AVLnode *tree_maximum(AVLnode *root);

	AVLnode tree_sucessor(AVLnode *x);
	AVLnode tree_predescessor(AVLnode *x);

	int balance(AVLnode &z);
	int node_height(AVLnode a);
	int max(int a, int b);
};

#endif
