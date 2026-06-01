#ifndef DIGITAL_BST_H
#define DIGITAL_BST_H
/*
	VANTAGENS:
	 - Não requer rotações.
	
	DESVANTAGENS:
	 - Desempenho depende do tamanho das chaves (n° de bytes);
	 - Não mantém as chaves em ordem.

	BUSCA:
	 - No nível k, comparamos o k-ésimo bit da chave de busca com o k-ésimo bit da chave corrente. 
	   (0 = vá à esquerda, 1 = vá à direita)

	PROPRIEDADE CHAVE:
	 - Toda chave em uma TRIE tree está em algum ponto do caminho definido por seus bits.
	   Bits = w = log2(n) = altura da TRIE tree

	EXTRAÇÃO DE CHAVES:
	 - Para extrair o i-ésimo bit:
	   key >> ((w - 1) - i) & 1
	
	INSERÇÃO:
	 - Encontrar a 1ª posição livre no caminho definido pelos bits da chave a ser inserida.
	   Não mantém chaves em ordem.

	REMOÇÃO:
	 a) Nó a ser removida é folha:
	    - Desconectá-lo do pai.
	 b) Nó a ser removido possui 1 ou 2 filhos:
	    - Substituí-se o nó por um descendente que seja folha;
	    - Após isso remove-se a folha.
*/

typedef struct 
{
	unsigned int c : 1;
}OneBit;

typedef struct TrieNode{
int		key;

TrieNode	*parent;
TrieNode	child[2];

} TrieNode;

class Tries 
{	
	private:
		int 	 w;
		TrieNode *root;
		TrieNode *array;

	public:
		Tries(int bits);
		~Tries();
		bool search(int k); 		// log2(n)
		bool insertion(TrieNode k); 	// log2(n)
		bool remove(int k);		// log2(n)
};


#endif
