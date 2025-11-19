#include "priority_bin.h"
#include <iostream>

Priority_bin::Priority_bin(int size): max(size)
{
    heap = new Node [size];
    this->size = 0;
}

Priority_bin::~Priority_bin()
{
    delete [] heap;
}

int Priority_bin::get_size()
{
    return size;
}

int Priority_bin::get_element(int index)
{
    return heap[index].valor;
}

int Priority_bin::is_empty()
{
    return (size == 0);
}

int Priority_bin::is_full()
{
    return (size == max);
}

void Priority_bin::shift_up(int index)
{
    int parent_idx = parent(index);

    while (index > 0 && heap[index].prioridade < heap[parent_idx].prioridade)
    {
        swap(index, parent_idx);

        index = parent_idx;
        parent_idx = parent(index);
    }
    return ;
}

void Priority_bin::shift_down(int index)
{
    int smallest, right;

    while (left_chld(index) < size)
    {
        smallest = left_chld(index);
        right = right_chld(index);

        if (right < size && heap[right].prioridade < heap[smallest].prioridade)
        {
            smallest = right;
        }

        if (heap[index].prioridade <= heap[smallest].prioridade)
        {
            break;
        }

        swap(index, smallest);
        index = smallest;
    }
    return ;
}

int Priority_bin::parent(int index)
{
    return (index - 1) / 2;
}

int Priority_bin::left_chld(int index)
{
    return (2 * index) + 1;
}

int Priority_bin::right_chld(int index)
{
    return (2 * index) + 2;
}

void Priority_bin::swap(int origin, int target)
{
    Node temp = heap[origin];

    heap[origin] = heap[target];
    heap[target] = temp;
    return ;
}

void Priority_bin::push(int element, int priority)
{
    if (is_full())
    {
        std::cout << "Lista de prioridade cheia." << std::endl;
        return ;
    }

    Node obj = {element, priority};

    heap[size] = obj;
    shift_up(size);

    size++;
    return ;
}

int Priority_bin::pop()
{   
    if (is_empty())
    {
        std::cout << "Lista de prioridade vazia." << std::endl;
        return -1;
    }

    Node return_value = heap[0];
    size--;

    Node ultimo = heap[size];

    if (size > 0)
    {
        heap[0] = ultimo;
        shift_down(0);
    }

    return return_value.valor;
}
