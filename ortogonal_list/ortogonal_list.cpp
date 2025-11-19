#include "ortogonal_list.h"
#include <iostream>

ortogonal_list::ortogonal_list()
{
    head = nullptr;
    size = 0;
}

OLnode* ortogonal_list::build(int **A, int n, int m)
{
    OLnode *map[n][m]; // static map

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            OLnode *nnode;
            nnode->key = A[i][j];

            map[i][j] = nnode;

            if (i != 0)
            {
                nnode->up = map[i - 1][j];
                map[i - 1][j]->down = nnode;
            }

            if (j != 0)
            {
                nnode->left = map[i][j - 1];
                map[i][j - 1]->right = nnode;
            }
        }
    }
    return map[0][0];
}

void ortogonal_list::transverse()
{
    OLnode *current_row = head;
    OLnode *current_col = nullptr;

    while (current_col != nullptr)
    {
        current_col = current_row;

        while (current_col != nullptr)
        {
            std::cout << current_col->key;
            current_col = current_row->right;
        }
        std::cout << std::endl;
        current_row = current_row->down;
    }

}