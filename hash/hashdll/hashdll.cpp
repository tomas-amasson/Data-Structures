#include "hash.h"

Hash::Hash(int size) : max(size)
{
	this->array = (Hash_dll *) malloc(sizeof(Hash_dll) * this->max);
}

Hashnode Hash::search(Hashnode *a)
{
	return Hash_search(array[h(a->key)], a);
}

void 	Hash::insert(Hashnode *a)
{
	Hash_insert_head(array[h(a->key)], a);
	return ;
}

void 	Hash::remove(Hashnode *a)
{
	hash_delete(array[h(x->key)]);
}
