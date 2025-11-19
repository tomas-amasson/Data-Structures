#ifndef ORTOGONAL_LIST
#define ORTOGONAL_LIST 

typedef struct {
    int key;
    OLnode *up;
    OLnode *down;
    OLnode *left;
    OLnode *right;
} OLnode;


class ortogonal_list
{
    private:
    OLnode *head;
    int size;
    
    public:
    ortogonal_list();
    OLnode* build(int **A, int n, int m);
    void transverse();

};

#endif