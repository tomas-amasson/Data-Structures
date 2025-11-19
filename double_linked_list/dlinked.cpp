#include <iostream>
#include "dlinked.h"

    

    
dlinked::dlinked()
{
            head = nullptr;
}
    
standart_node* dlinked::get_head() const
{
            return head;
}

void   dlinked::set_head(standart_node *h)
{
    head = h;
}

void dlinked::add_head(int value)
{
    standart_node *node = new standart_node;
    node->key   = value;
    node->prev  = nullptr;
    node->next  = head;
    
    if (head != nullptr)
    {
        standart_node *previous = head;
        previous->prev = node;                
    }
    
    
    head = node;
    return ;
}

void dlinked::add_tail(int value)
{
    standart_node *node = new standart_node;
    node->key   = value;
    node->next  = nullptr;
    
    
    if (head == nullptr)
    {
        node->prev = nullptr;
        head = node;
        return ;
    }
    standart_node *tracker = head;
    while (tracker->next != nullptr)
    {
        tracker = tracker->next;
    }
    tracker->next = node;
    standart_node *pos = tracker->next;
    pos->prev  = tracker;
    tracker->next = node;
    return ;               
}

void dlinked::add_pos(int key, int index)
{
    standart_node *node = new standart_node;
    node->key   = key;
    
    standart_node *tracker = head;
    if (index == 0)
    {
        add_head(key);
        return ;
    }
    
    while (index != 0 && tracker != nullptr)
    {
        tracker = tracker->next;
        index--;
    }
    
    if (tracker == nullptr)
    {
        add_tail(key);
        return ;
    }
    node->next = tracker;
    node->prev = tracker->prev;
    
    standart_node *previous = tracker->prev;
    previous->next = node;
    tracker->prev = node;
}

void dlinked::add_after(int key, standart_node *target)
{
    standart_node *node = new standart_node;
    node->key   = key;
    standart_node *tracker = head;
    if (target->next == nullptr)
    {
        add_tail(key);
        return ;
    }
    int idx = 0;
    while (tracker->prev != target)
    {
        tracker = tracker->next;
        idx++;
    }
    add_pos(key, idx);
    return ;
}

void dlinked::add_before(int key, standart_node *target)
{
    standart_node *node = new standart_node;
    node->key   = key;
    standart_node *tracker = head;
    if (target->prev == nullptr)
    {
        add_head(key);
        return ;
    }
    int idx = 0;
    while (tracker != target)
    {
        idx++;
        tracker = tracker->next;
    }
    add_pos(key, idx);
    return ;
}

void dlinked::remove_pos(int index)
{
    standart_node *tracker = head;
    
    if (index == 0)
    {
        remove_head();
        return ;
    }
    while (index != 0 && tracker->next != nullptr)
    {
        tracker = tracker->next;
        index--;
    }
    if (tracker->next == nullptr)
    {
        remove_tail();
        return ;
    }
    standart_node *previous = tracker->prev;
    previous->next  = tracker->next;
    standart_node *forward  = tracker->next;
    forward->prev   = previous;
    delete tracker;
    return ;
}

void dlinked::remove_head()
{
    standart_node* temp = head->next;
    delete head;
    head = temp;
    return ;
}

void dlinked::remove_tail()
{
    standart_node *tracker = head;
    while (tracker->next != nullptr)
    {
        tracker = tracker->next;
    }
    tracker->prev->next = nullptr;
    delete tracker;
    return ;
}

void dlinked::print()
{
    standart_node *tracker = head;
    while (tracker != nullptr)
    {
        std::cout << *tracker << std::endl;
        tracker = tracker->next;
    }
}

std::ostream & operator<<(std::ostream &output, const standart_node &n)
{
    output << n.key;
    return output;
}