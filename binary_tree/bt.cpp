#include <iostream>
#include "bt.h"
#include <time.h>
#include <stdlib.h>

std::ostream& operator<<(std::ostream &output, const tree_node &tn)
{
    output << tn.key;
    return output;
}

Binary_Tree::Binary_Tree()
{
    root = nullptr;
    size = 0;
}

void Binary_Tree::tree_walk_inorder(tree_node *walker)
{
    if (walker != nullptr)
    {
        tree_walk_inorder(walker->left);
        
        std::cout << *walker << std::endl;

        tree_walk_inorder(walker->right);
    }
    return ;
}

void Binary_Tree::tree_walk_preorder(tree_node *walker)
{

    if (walker != nullptr)
    {
        std::cout << *walker << std::endl;

        tree_walk_preorder(walker->left);
        tree_walk_preorder(walker->right);
    }
    return ;
}

void Binary_Tree::tree_walk_postorder(tree_node *walker)
{
    if (walker != nullptr)
    {
        tree_walk_postorder(walker->left);
        tree_walk_postorder(walker->right);

        std::cout << *walker << std::endl;
    }
    return ;
}

void Binary_Tree::tree_insert_naive(tree_node *tracker, int key)
{
    tree_node *nt = new tree_node;
    nt->key       = key;

    if (tracker == nullptr)
    {
        nt->father  = nullptr;
        nt->left    = nullptr;
        nt->right   = nullptr;
    }

    else if (tracker->left == nullptr)
    {
        nt->left    = nullptr;
        nt->father  = tracker;
        nt->right   = nullptr;

        tracker->left  = nt; 
    }

    else if (tracker->right == nullptr)
    {
        nt->father = tracker;
        nt->left   = nullptr;
        nt->right  = nullptr;

        tracker->right = nt;
    }

    else 
    {
        srand(time(NULL));
        int random = rand() % 2;
        if (random == 1)
            tree_insert_naive(tracker->right, key);
        else 
            tree_insert_naive(tracker->left,  key);
    }
}

tree_node*  Binary_Tree::tree_search_naive(tree_node *tracker, int key)
{
    if (tracker == nullptr)
        return NULL;
    if (tracker->key == key)
        return tracker;

    tree_node *left = tree_search_naive(tracker->left, key);
    if (left != nullptr)
        return left;
    
        return tree_search_naive(tracker->right, key);
}