#include"binary_trees.h"
#include <stdlib.h>
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *newleft;
    binary_tree_t *tmp;
    
    if (!parent)
        return NULL;
    tmp=NULL;
    if (parent->left)
    {
        tmp=parent->left;
    }
    newleft=binary_tree_node(parent, value);
    if (!newleft)
        return NULL;
    parent->left= newleft;

    newleft->left=tmp;
    if (tmp)
        tmp->parent=newleft;
    return newleft;
}