#include "tries.h"

Tries::Tries(int bits)
{
	this->w 	= bits;
	this->array 	= (TrieNode *) malloc(sizeof(TrieNode) * );
	this->root  	= nullptr;
}

Tries::~Tries()
{
	free(this->array);
}

bool Tries::search(int k)
{
	TrieNode *u = this->root;
	int c;

	for (int i = 0; i < this->w; i++)
	{
		c = (k >> ((this->w - 1) - i)) & 1;
		if (u->key != k)
			u = u.child[c];
		else
			return true;

		if (u == nullptr)
			return false;
	}
}

bool Trie::insert(TrieNode *k)
{
	TrieNode *u = this->root;
	int c;

	for (int i = 0; i < this->w; i++)
	{
		c = (k >> ((this->w - 1) - i)) & 1;
		if (u->key == k)
			return false;

		if (u->child[c] == nullptr)
			break;

		u = u->child[c];
	}
	u->child[c] = k;
	k->parent = u;

	return true;
}


bool Trie::remove(int k)
{
	TrieNode *u = this->root;
	OneBit ob;
	int i;

	for (i = 0; i < this->w; i++)
	{
		ob.c = ((this->w - 1) - i) & 1;
		if (u->key == k)
			break;
		if (u->child[ob.c] == nullptr)
			return false;
		u = u->child[ob.c];
	}	

	if (i = (this->w - 1))
	{
		u->parent->child[ob.c] = nullptr;
		u->parent = nullptr;
	}

	else 
	{
		TrieNode *z = u;

		while (z->child[ob.c] != nullptr || z->child[ob.c] != nullptr)
		{
			if (z->child[0] != nullptr)
			{
				z = z->child[0];
				ob.c = 0;
			}
			else
			{
				z = z->child[1];
				ob.c = 1;
			}
		}

		u->key = z->key;
		z->parent->child[ob.c] = nullptr;
		z->parent = nullptr;
		free(z);
	}
}
