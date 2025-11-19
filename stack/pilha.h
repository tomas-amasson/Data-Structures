#ifndef PILHA_H
#define PILHA_H
class Pilha
{
    private:
        static int npl;
        int size;
        const int max;
        
        int *list;

    public:
        Pilha(int size);
        ~Pilha();

        int pop();
        int push(int element);
        void newsize();
        int look_ahead();
        int is_empty();
        int get_size();
};

#endif 