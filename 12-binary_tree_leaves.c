#include"binary_trees.h"
#include <stdlib.h>
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t leaves=0;
    if (!tree)
        return 0;
    if (!tree->left && !tree->right)
        return 1;
    leaves += binary_tree_leaves(tree->left);
    leaves += binary_tree_leaves(tree->right);
    return leaves;
}