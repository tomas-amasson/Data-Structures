#include <iostream>

#ifndef DLINKED_H
#define DLINKED_H

typedef struct standart_node
{
    int key;
    standart_node *next;
    standart_node *prev;

    friend std::ostream & operator<<(std::ostream&, const standart_node&);
} standart_node;

class dlinked {
    private:
        standart_node *head;
    
    public:
        dlinked();

        void set_head(standart_node*);
        standart_node* get_head() const;
        void add_head(int key);
        void add_tail(int value);
        void add_pos(int key, int index);
        void add_after(int key, standart_node *target);
        void add_before(int key, standart_node *target);
        void remove_pos(int index);
        void remove_head();
        void remove_tail();
        void print();
};

#endif