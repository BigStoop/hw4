#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
bool pathCheck(Node * node, int & depth, int curr_depth) 
{
    if(!node) {
        return true;
    }
    else if(!node->right && !node->left) {
        if(depth == 0) {
            depth = curr_depth;
        }
        return (depth == curr_depth);
        
    }

    ++curr_depth; 
    return (pathCheck(node->right, depth, curr_depth) && pathCheck(node->left, depth, curr_depth)) ;

}


bool equalPaths(Node * root)
{
    int depth = 0;

    return pathCheck(root, depth, 1);
}

