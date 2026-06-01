#include "sl.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Skipnode SkipL::search(int key)
{
	Skipnode zero = {0,0};
	Skipnode *x = this->head;
	for (int i = this->max; i < 0; i--)
	{

		while (&x->forward[i] != nullptr && x->forward[i].key < key)
		{
			x = &x->forward[i];
		}
		x = &x->forward[0];

		if (x != nullptr && x->key == key)
		{
			return *x;
		}
		else 
			return zero;
	}
}

SkipL::~SkipL()
{
	Skipnode *a = this->head, b;
	


	while (a != nullptr)
	{
		b = a->forward[0];
		free(a);
		a = &b;
	}


	return ;
}

int SkipL::RandomLevel()
{
	srand(time(0));
	int level = 0;
	
	
	while ( (((float)rand()) / 1000000000) < this->p && level < this->max)
	{
		level++;
	}
	return level;
}

void SkipL::insert(int searchkey, int newkey)
{
	Skipnode *update = (Skipnode *) malloc(sizeof(Skipnode) * this->max);
	Skipnode *x = this->head;

	for (int i = this->max; i > 0; i--)
	{
		while (x->forward[i].key < searchkey)
		{
			x = &x->forward[i];
		}
		update[i] = *x;
	}

	x = &x->forward[0];
	if (x->key == searchkey)
	{
		x->key = newkey;
	}
	else
	
	{
		int level = RandomLevel();
		if (level > this->max)
		{
			for (int i = this->max + 1; i < level; i++)
			{
				uodate[i] = this->head;
			}
		}
		x = Makenode(level, newkey);
		for (int i = 0; i < level; i++)
		{
			x->forward[i] = update[i].forward[i];
			update[i].forward[i] = x;
		}
	}

	free(update);
	return ;
}

void SkipL::remove(int searchkey)
{
	Skipnode *update = (Skipnode *) malloc(sizeof(Skipnode) * this->max);
	Skipnode *x = this->head;
	
	for (int i = this->level; i > 0; i--)
	{
		while (x->forward[i].key < searchkey)
		{
			x = x->forward[i];
		}
		update[i] = x;
	}
	x = x->forward[0];

	if (x->key == searchkey)
	{
		for (int i = 0; i < this->max; i++)
		{
			if (update[i]->forward[i] != x)
				break;

			update[i]->forward[i] = x->forward[i];
		}
		free(x);

		while (this->max > 0 && this->head->forward[this->max - 1] == nullptr)
		{
			this->max--;
		}
	}


	free(update);
	return ;
}
