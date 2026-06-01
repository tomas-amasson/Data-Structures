#ifndef BINARY_HEAP_MAX_H
#define BINARY_HEAP_MAX_H


/* ACCESS

left son    2i + 1
right son   2i + 2
father      floor((i - 1) / 2)
*/

typedef struct {
    int key;
    int p;
} node;

class bheapM
{
    private:
        node *data;
        int  tail;
        const int max;

    public:
        bheapM(int max);
        ~bheapM();

        void shift_up();
        void shift_down(int i);

        void enqeue(int key, int p);
        int  deqeue();

        int get_tail() const;

        void swap(node &a, node &b);
        void swapint(int *a, int *b);
        void heapify(node *L, int n, int start);
        int* build_max_heap(int *L, int n);
        void heapsort(int *L, int n);
};

#endif