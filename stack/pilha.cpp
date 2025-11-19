#include "pilha.h"
#include <iostream>

int Pilha::npl = 0;

Pilha::Pilha(int size) : max(size)
{
    this->size = 0;

    list = new int [max];
    npl++;
}


Pilha::~Pilha()
{
    npl--;
    delete [] list;
}

int Pilha::push(int element)
{
    this->size++;
    list[size - 1] = element;
    return element;
}

int Pilha::is_empty()
{
    if (size)
    {
        return 0;
    }
    return 1;
}

int Pilha::pop()
{
    int temp;

    if (size > 0)
    {
        temp = list[size - 1];
        this->size--;
        return temp;
    }
    
    std::cout << "Empty list." << std::endl;
    return -999;
}


int Pilha::look_ahead()
{
    if (size)
    {
        return list[size - 1];
    }
    std::cout << "Empty list." << std::endl;
    return -999;

}

int Pilha::get_size()
{
    return size;
}