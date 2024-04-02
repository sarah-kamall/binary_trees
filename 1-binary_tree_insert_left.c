#include"binary_trees.h"
#include <stdlib.h>
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (!parent)
        return NULL;
    binary_tree_t *tmp=NULL;
    if (parent->left)
    {
        tmp=parent->left;
    }
    binary_tree_t *newleft=binary_tree_node(parent, value);
    if (!newleft)
        return NULL;
    parent->left= newleft;

    newleft->left=tmp;
    if (tmp)
        tmp->parent=newleft;
    return newleft;
}