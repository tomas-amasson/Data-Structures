
#ifndef PRIORITY_BIN_H
#define PRIORITY_BIN_H

typedef struct
{
    int valor;
    int prioridade;
} Node;


class Priority_bin
{
    private:
        const int max;
        int size;
        Node *heap;

    public:
        Priority_bin(int size= 10);
        ~Priority_bin();

        void push(int element, int priority);
        int pop();
        void shift_up(int index);
        void shift_down(int index);
        int parent(int index);
        void swap(int origin, int target);
        int left_chld(int index);
        int right_chld(int index);

        int get_size();
        int is_empty();
        int is_full();
        int get_element(int index);
};
#endif