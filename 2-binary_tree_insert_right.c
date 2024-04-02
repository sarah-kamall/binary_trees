#include"binary_trees.h"
#include <stdlib.h>
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *tmp=NULL;
    binary_tree_t *newright;

    if (!parent)
        return NULL;
    tmp=NULL;
    if (parent->right)
    {
        tmp=parent->right;
    }
    newright=binary_tree_node(parent, value);
    if (!newright)
        return NULL;
    parent->right= newright;

    newright->right=tmp;
    if (tmp)
        tmp->parent=newright;
    return newright;
}