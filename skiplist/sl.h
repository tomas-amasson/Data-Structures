#ifndef SKIP_LIST_H
#define SKIP_LIST_H

/*
- ESTRUTURA DE DADO PROBABILISTICA
- BUSCA, INSERÇÃO E REMOÇÃO: O(logn)	

- FATOR DE DISPERSÃO: controla a probabilidade de uma chave do nível (i) seja replicada no nível (i + 1).
	resulta em uma hierarquia de listas encadeadas, de modo que quanto maior o nível, mais esparsa a lista;
	p = 1 / d.

	1. A camada inferior (nível 0): é uma lista encadeada ordenada;
	2. Cada camada superior via expressa, com uma fração de (p) dos elementos da camada inferior;


2:	-	-> NULL

1:	-> 4		-> NULL

0:	-> 4	-> 6	-> 8	-> 10

- INSERÇÃO: antes de inserir um nó é preciso sortear um nível para esse.
	Para, d = 2:
		p = 1/d = 1/2

				    1	       2    3  
		|-------------------|----------|----|--|--|
		0%		    p			  100%

			    
	PROBABILIDADE DO NÍVEL (i):
		P(0) = 1
		P(1) = 0.5
		P(2) = 0.25
		P(3) = 0.125
		...

	INSERÇÃO = BUSCA 	+ ENCADEAMENTO = O(logd(n))
		   O(logd(n)) 	+ O(k)
				  O(1 + logd(n))


- REMOÇÃO: após a remoção de um nó é necessário checar se o nível deve ser desativado.

	REMOÇÃO = 	BUSCA		+ ENCADEAMENTO = O(logd(n))
			O(logd(n))	+ O(k)
					  O(1 + logd(n))

*/


typedef struct Skipnode {
int		key;
Skipnode 	*forward;

} Skipnode;

class SkipL {

	private:
		int max;
		int d;
		float p;
		Skipnode *head;

	public:
		SkipL(int max, int d): max(max), d(d) {p = (1.0)/d;this->head = nullptr;}
		~SkipL();

		Skipnode search(int key);
		void insert(int searchkey, int newkey);
		void remove(int searchkey);

		int RandomLevel();
		Skipnode *Makenode(int searchkey, newkey);
};


#endif
