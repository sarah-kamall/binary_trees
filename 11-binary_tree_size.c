#include"binary_trees.h"
#include <stdlib.h>
size_t binary_tree_size(const binary_tree_t *tree)
{
    size_t tsize=0;

    if (!tree)
        return 0;
    tsize +=1 ;
    tsize+= binary_tree_size(tree->left);
    tsize+= binary_tree_size(tree->right);
    return tsize;
}