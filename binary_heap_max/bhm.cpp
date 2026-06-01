#include "bhm.h"
#include <iostream>

// Para acessar os filhos:
// Direita: 2n + 2
// Esquerda: 2n + 1
// Para acessar o pai:
// piso((n - 1)/2)

bheapM::bheapM(int max): max(max)
{
    data = new node [max];
    tail = -1;
}

bheapM::~bheapM()
{
    delete [] data;
}

void bheapM::enqeue(int key, int p)
{
    if (tail == max - 1)
    {
        std::cout << "Overflow" << std::endl;
        return ;
    }

    tail++;
    data[tail].key = key;
    data[tail].p   = p;

    shift_up();
}

void bheapM::shift_up()
{
    int son = tail, son_p = data[son].p;
    int parent = (son - 1) / 2, parent_p = data[parent].p;

    while (son > 0 && son_p > parent_p)
    {
        swap(data[son], data[parent]);
        son = parent;
        parent = (son - 1) / 2;

        son_p = data[son].p;
        parent_p = data[parent].p;
    }
}

void bheapM::swap(node &a, node &b)
{
    node temp = b;

    b.key = a.key;
    b.p   = a.p;

    a.key = temp.key;
    a.p   = temp.p;

    return ;
}

void bheapM::swapint(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
    return;
}

int bheapM::deqeue()
{
    if (tail == -1)
    {
        std::cout << "Underflow" << std::endl;
        return ;
    }

    int key = data[0].key;
    swap(data[0], data[tail]);

    tail--;
    shift_down(0);

    return key;
}

void bheapM::shift_down(int i)
{
    int parent = i, parent_p = data[parent].p;
    int left   = 2 * parent + 1, right = 2 * parent + 2;

    int smallest = parent;

    if (left <= tail && parent_p < data[left].p)
        smallest = left;
    
    if (right <= tail && data[smallest].p < data[right].p)
        smallest = right;

    if (smallest != parent)
    {
        swap(data[parent], data[smallest]);
        shift_down(smallest);
    }
}

void bheapM::heapify(node *L, int n, int start)
{
    int largest = start;
    int left    = 2 * start + 1, right = 2 * start + 2;

    if (left <= n && L[start].key < L[left].key)
        largest = left;

    if (right <= n && L[start].key < L[right].key)
        largest = right;

    if (largest != start)
    {
        swap(L[start], L[largest]);
        heapify(L, n, largest);
    }
}

int* bheapM::build_max_heap(int *L, int n)
{
    node *data = nullptr;
    node *add  = nullptr;

    for (int i = 0; i < n; i++)
    {
        add = new node;
        add->key = L[i];
        add->p   = L[i];

        data[i] = *add;
    }

    for (int i = (n / 2) - 1; i < 0; i--)
        heapify(data, n, i);

    return L;
}

void bheapM::heapsort(int *L, int n)    
{
    build_max_heap(L, n);
    for (int i = n; i > 0; i--)
    {
        swapint(&L[0], &L[i]);
        //....
    }
}
