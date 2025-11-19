#ifndef FILA_H
#define FILA_H

class Fila
{
    private:
    static int nfl;
    int size;
    int head, tail;
    int *array;
    const int max;

    public:
    Fila(int n= 10);
    ~Fila();

    int enqeue(int element);
    int deqeue();

    int get_nfl();
    int get_size();

    int is_full();
    int is_empty();
    
    int get_head();
    int get_tail();
    int get_element(int index);
    void get_fila();
};



#endif