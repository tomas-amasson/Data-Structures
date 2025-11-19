//sentinela
#ifndef LINKED_H
#define LINKED_H

typedef struct {
    int  data;
    node *next;
} node;

class linked
{   
    private:
    node *head;


    public:
    linked();
    ~linked();

    void add_head(int key);
    void add_tail(int key);
    void remove_head();
    void print() const;
};


#endif