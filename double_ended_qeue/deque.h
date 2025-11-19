#ifndef DEQUE_H
#define DEQUE_H

class Deque
{
    private:
        int *array;
        int size;
        const int max;

        int end;
        int start;
    public:
        Deque(int n);
        ~Deque();

        bool is_empty();
        bool is_full();

        int add_start(int key);
        int add_end(int key);

        int remove_start();
        int remove_end();

        int get_element(int index);
        int get_end();
        int get_start();
};

#endif 