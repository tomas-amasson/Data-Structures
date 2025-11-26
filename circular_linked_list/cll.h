#include <iostream>

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

typedef struct node{
    int key;
    node* next;
    node* prev;
    
    friend std::ostream & operator<<(std::ostream&, const node &);
} node;

class cll
{
    private:
        node *head;

    public:
        cll();
        void add_head(int key);
        void add_tail(int key);

        void set_head(node* h);
        node* get_head() const;

            
        void remove_head();
        void remove(int key);
        void print() const;
};

#endif