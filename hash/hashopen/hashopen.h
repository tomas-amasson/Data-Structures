#ifndef HASH_OPEN_H
#define HASH_OPEN_H

typedef struct {
int 	k;
} HOnode;

class HashOpen
{
	private:
		HOnode *T;
	public:
		void HOinsert(int k);

		HOnode HOsearch(int k);

};

#endif
