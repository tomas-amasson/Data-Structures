#include "fila.h"
#include <iostream>

int Fila::nfl = 0;

Fila::Fila(int n) : max(n)
{
    size = 0;
    head = 0;
    tail = 0;

    if (n < 0)
    {
        n = 0;
    }
    array = new int [n];

    nfl++;
}

Fila::~Fila()
{
    if (size != 0)
    {
        delete [] array;
    }
    
    nfl--;
}

int Fila::enqeue(int element)
{
    if (is_full())
    {
        std::cout << "List is full." << std::endl;
        return 9999;
    }

    array[tail] = element;

    if (tail == (max - 1))
    {
        tail = 0;
    }
    else
    {
        tail++;
    }

    size++;
    return element;
}

int Fila::deqeue()
{
    if (is_empty())
    {
        std::cout << "List is empty." << std::endl;
        return 9999;
    }

    int temp = array[head];
    if (head == (max - 1))
    {
        head = 0;
    }
    else
    {
        head++;
    }

    
    size--;
    return temp;
}

int Fila::get_nfl()
{
    return nfl;
}

int Fila::get_size()
{
    return size;
}

int Fila::is_full()
{
    if (size == max)
    {
        return 1;
    }
    return 0;
}

int Fila::is_empty()
{
    if (size == 0)
    {
        return 1;
    }
    return 0;
}

int Fila::get_head()
{
    return head;
}

int Fila::get_tail()
{
    return tail;
}

int Fila::get_element(int index)
{
    return array[index];
}

void Fila::get_fila()
{
    for (int i = get_head(), j = 0; j < get_size(); j++)
    {
        std::cout << get_element(i) << std::endl;
        
        if (i + 1 > 3)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
}