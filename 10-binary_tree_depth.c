#include"binary_trees.h"
#include <stdlib.h>
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (!tree)
        return 0;
    if (tree->parent)
        return 1 + binary_tree_depth(tree->parent);
    else
        return 0;

}