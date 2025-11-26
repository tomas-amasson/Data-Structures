#include <iostream>
#include "cll.h"

cll::cll()
{
    head = nullptr;
}


void cll::add_head(int key)
{
    node *n = new node;
    n->key  = key;
    n->next = nullptr;
    n->prev = nullptr;

    if (head == nullptr)
    {   
        head = n;
        n->prev = n;
        n->next = n;

        return ;
    }

    head->prev->next = n;
    n->prev = head->prev;
    n->next = head;

    head->prev = n;
    head = n;
    
    return ;
}

void cll::add_tail(int key)
{
    node *n = new node;

    if (head == nullptr)
    {
        head = n;
        n->next = n;
        n->prev = n;

        return ;
    }

    n->next = head;
    n->prev = head->prev;

    head->prev->next = n;
    head->prev = n;

    return ;
}

void cll::set_head(node *h)
{
    head = h;
}

node* cll::get_head() const
{
    return head;
}

void cll::remove_head()
{

    if (head->next == head)
    {
        delete head;
        return ;
    }

    node *save = head->next;
    head->prev->next = save;
    save->prev = head->prev;
    
    delete head;
    head = save;

    return ;
}

void cll::remove(int key)
{
    if (head == nullptr)
        return ;


    bool repeat = false;
    node *tracker = head;
    while (tracker->key != key) 
    {
        
        tracker = tracker->next;
        if (head == tracker)
        {
            repeat = true;
            break;
        }
    }

    if (repeat)
        return ;
    


    tracker->prev->next = tracker->next;
    tracker->next->prev = tracker->prev;

    delete tracker;
}

void cll::print() const
{
    node *tracker = head;

    std::cout << tracker << std::endl;
    tracker = tracker->next;

    while (tracker != head)
    {
        std::cout << tracker << std::endl;
        tracker = tracker->next;
    }

    return ;
}