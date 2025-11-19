// binary search tree
#include <iostream>

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct tree_node {
    int key;

    tree_node *father;
    tree_node *left  ;
    tree_node *right ;

    friend std::ostream& operator<<(std::ostream&, const tree_node&);
} tree_node;


class bst 
{
    private:
        tree_node* root;
        int size;
    
    public:
        bst();
        void tree_insert(int key);
        tree_node* tree_min(tree_node* tracker);
        tree_node* tre_max (tree_node* tracker);
        tree_node* rec_tree_search(tree_node* tracker, int key);
        tree_node* tree_search(int key);
        tree_node* tree_sucessor(tree_node *current);
        tree_node* tree_predecessor(tree_node *current);
};

#endif