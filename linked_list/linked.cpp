#include "linked.h"
#include <iostream>

linked::linked()
{
    this->head = nullptr;
}

linked::~linked()
{
    while (head != nullptr)
        remove_head();
}

void linked::add_head(int key)
{
    node *new_ll = new node{key, head};
    head = new_ll;
}

void linked::add_tail(int key)
{
    node *new_ll = new node{key, nullptr};

    if (head == nullptr)
    {
        head = new_ll;
        return;
    }

    node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;
    
    temp->next = new_ll;

}

void linked::remove_head()
{
    if (head == nullptr)
        return;
    
        node *temp = head;
        head = head->next;
        delete temp;
}

void linked::print() const
{
    node *temp = head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    return;
}   
