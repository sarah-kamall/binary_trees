#include"binary_trees.h"
#include <stdio.h>

double poww(double base, int exponent) {
  // Handle special cases
  if (exponent == 0) {
    return 1.0; // Anything to the power of 0 is 1 (except for 0^0)
  } else if (exponent < 0) {
    return 1.0 / poww(base, -exponent); // Handle negative exponents
  } else if (base == 0.0 && exponent > 0) {
    return 0.0; // 0 to any positive power is 0
  }

  // Recursive implementation
  return base * poww(base, exponent - 1);
}
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
int binary_tree_is_full(const binary_tree_t *tree)
{
    int fullnodes;
    if (!tree)
        return 0;
    fullnodes= poww(2,binary_tree_heighttmp(tree))-1;
    if ((int)binary_tree_sizetmp(tree)==fullnodes)
        return 1;
    else
        return 0;
}