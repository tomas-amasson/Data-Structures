#include "bst.h"
#include <iostream>

std::ostream& operator<<(std::ostream &output, const tree_node &n)
{
    output << n.key;
    return output;
}


bst::bst()
{
    root = nullptr;
    size = 0;
}


void bst::tree_insert(int key)
{
    tree_node *current = root;
    tree_node *previous = nullptr;

    tree_node *tn = new tree_node;
    tn->key       = key;
    tn->right     = nullptr;
    tn->left      = nullptr;

    while (current != nullptr)
    {
        previous = current;
        if (tn->key < current->key)
            current = current->left;

        else 
            current = current->right;
    }

    tn->father = previous;

    if (previous == nullptr)
        root = previous;
    
    else 
    {
        if (tn->key < previous->key)
            previous->left = tn;
        
        else 
            previous->right = tn;
    }
}

tree_node* bst::tree_min(tree_node *tracker)
{
    while (tracker != nullptr)
    {
        tracker = tracker->left;
    }
    return tracker;
}

tree_node* bst::tree_max(tree_node *tracker)
{
    while (tracker != nullptr)
    {
        tracker = tracker->right;
    }
    return tracker;
}

tree_node* bst::rec_tree_search(tree_node* tracker, int key)
{
    tree_node *rval;

    if (tracker == nullptr || tracker->key == key)
        return tracker;

    if (key < tracker->key)
        rval = rec_tree_search(tracker->left, key);
    
    else 
        rval = rec_tree_search(tracker->right, key);

    return rval;
}

tree_node* bst::tree_search(int key)
{
    tree_node *tracker = root;
    while (tracker != nullptr && key != tracker->key)
    {
        if (key < tracker->key)
            tracker = tracker->left;

        else 
            tracker = tracker->right;
    }
    return tracker;
}

tree_node* bst::tree_sucessor(tree_node *current)
{   
    if (current->right != nullptr)
        return tree_min(current->right);
    
    else
    {
        tree_node *previous = current->father;

        while (previous != nullptr && current == previous->right)
        {
            current = previous;
            previous = previous->father;
        }
        return previous;
    }
        
}

tree_node* bst::tree_predecessor(tree_node *current)
{
    if (current->left != nullptr)
        return tree_max(current->left);

    tree_node *previous = current->father;

    while (previous != nullptr && current == previous->left)
    {
        current = previous;
        previous = previous->father;
    }
    
    return previous;
}

void bst::transplant(tree_node *u, tree_node *v)
{
    if (u->father == nullptr)
        root = v;
    
    else if (u == u->father->left)
    {
        u->father->left = v;
        u->right = nullptr;
    }

    else 
    {
        u->father->right = v;
        u->right = nullptr;
    }

    if (v != nullptr)
    {
        v->father = u->father;
        u->father = nullptr;
    }

    return ;
}