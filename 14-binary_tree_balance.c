#include"binary_trees.h"
#include <stdlib.h>
size_t binary_tree_heighttmp(const binary_tree_t *tree)
{
    size_t heightl =0,heightr=0;
    if (!tree)
    {
        return 0;

    }
    else 
    {
        if (!tree->left && !tree->right)
            return 1;
        heightl=1+binary_tree_heighttmp(tree->left);
        heightr=1+binary_tree_heighttmp(tree->right);
        if(heightl>heightr)
            return heightl;
        else
            return heightr;
    }
    
}
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return 0;
    return ((int)binary_tree_heighttmp(tree->left)-(int)binary_tree_heighttmp(tree->right));

}