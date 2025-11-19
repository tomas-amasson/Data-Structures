#include <iostream>
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Estrutura dinâmica hierárquica

typedef struct tree_node {
    int key;

    tree_node *father;
    tree_node *left  ;
    tree_node *right ;

    friend std::ostream& operator<<(std::ostream&, const tree_node&);
} tree_node;



class Binary_Tree {
    private:
        tree_node *root;
        int size;

    public:
        Binary_Tree();

        void tree_walk_inorder  (tree_node *walker);
        void tree_walk_preorder (tree_node *walker);
        void tree_walk_postorder(tree_node *walker);
        void tree_insert_naive  (tree_node *tracker, int key);
        tree_node*  tree_search_naive  (tree_node *tracker, int key);
};

#endif