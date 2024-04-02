#include"binary_trees.h"
#include <stdlib.h>
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t heightl =0,heightr=0;
    if (!tree)
    {
        return 0;

    }
    else 
    {
        if (!tree->left && !tree->right)
            return 0;
        heightl=1+binary_tree_height(tree->left);
        heightr=1+binary_tree_height(tree->right);
        if(heightl>heightr)
            return heightl;
        else
            return heightr;
    }
    
}