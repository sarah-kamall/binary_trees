#include"binary_trees.h"
#include <stdlib.h>
size_t binary_tree_sizetmp(const binary_tree_t *tree)
{
    size_t tsize=0;

    if (!tree)
        return 0;
    tsize +=1 ;
    tsize+= binary_tree_sizetmp(tree->left);
    tsize+= binary_tree_sizetmp(tree->right);
    return tsize;
}
size_t binary_tree_leavestmp(const binary_tree_t *tree)
{
    size_t leaves=0;
    if (!tree)
        return 0;
    if (!tree->left && !tree->right)
        return 1;
    leaves += binary_tree_leavestmp(tree->left);
    leaves += binary_tree_leavestmp(tree->right);
    return leaves;
}
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    return (binary_tree_sizetmp(tree)-binary_tree_leavestmp(tree));

}