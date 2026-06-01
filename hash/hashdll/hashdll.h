#ifndef HASH_H
#define HASH_H

/* HASH

- TABELA DE ACESSO DIRETO (TAD)
  Array de m slots: TAD[m];

- PROBLEMA: estrutura não escalável, devido ao alto custo de memória.
- SOLUÇÃO: a chave k é mapeada para o slot h(k), onde h é uma função hash, reduzindo o espaço de |u| para n.
  Entretanto, existem que h(k) = h(k2), logo, é necessário haver tratamento de colisões. 

- FATOR DE COMPLEXIDADE (Busca)
  Fator de carga = n/m

  sendo,
  n: número de chaves
  m: número de lista duplamente linkadas

  Visa-se obter a mesma distribuição de chaves em todas as listas

  T(n) = 1/n * Somatório de i = 1 até n [ 1 + Somatório de j = i - 1 até n [1/m]]
  T(n) = 1/n * Somatório de i = 1 até n [ 1 + 1/m * (n - i)]
  T(n) = 1/n * n + 1/(n * m) * Somatório de i = 1 até n [(n - i)]
  T(n) = 1 + 1/(n * m) * (n² - (n² + n)/2)
  T(n) = 1 + n/m - (n + 1)/(2 * m)
  T(n) = 1 + FATOR DE CARGA - 1/2 * n/m - 1/2m
  T(n) = 1 + FATOR DE CARGA - 1/2 * FATOR DE CARGA - n/2nm
  T(n) = 1 + 1/2 * FATOR DE CARGA - FATOR DE CARGA * 1/2n

  para obter O(), é necessário aplicar o limite, portanto:
  O(1 + FATOR DE CARGA)


- CASOS

  Se, n = C * m => FATOR DE CARGA = Cm/m = C (ou seja, o fator de carga é constante)
  Portanto, Busca e Remoção são O(1)

- METÓDOS:

° DIVISÃO: h(x) = x % m
  - PROBLEMAS
  Deve-se evitar m = 2^P (como potência de 2), visto que gera valores de chaves hash não equiprováveis. Ou seja, o acesso para de ser em tempo constante.
  - BONS m's: números primos grandes (maior do que qualquer chave possível), não possui multiplos.

° MULTIPLICAÇÃO: parâmetro adicional A, 0 < A < 1. h(x) = Floor( m([x * A] % 1) )  
  - BONS m's: m = 2^P
  - BONS A's: número com muitas casas decimais.

° HASHING UNIVERSAL: escolha aleatória de funções hash.


 */
typedef struct {
int 	key;
} Hashnode;

typedef struct Hashlist {
Hashlist	*prev;
Hashlist	*prox;

Hashnode	value;
} Hashlist;

typedef struct {
Hashlist	*head;
int 		size;
} Hash_dll;

class Hash {

	private:
	Hashnode *array;
	const int max;

	public:
	Hash();
	~Hash();

	Hashnode search(int i);
	void 	 remove(Hashnode *x);
	void	 insert(Hashnode *a);
	

	Hash_insert_head(int pos, Hashnode *a);
	Hash_remove(int pos, Hashnode *a);
	Hash_search(int pos, Hashnode *a);
};

#endif
