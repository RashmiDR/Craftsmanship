//
//  main.cpp
//  trees
//
//  Created by Rashmi Devarahalli on 3/10/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#include <iostream>

#include "binaryTree.h"

BinaryTree* createBinaryTree();

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    BinaryTree *binaryTree = createBinaryTree();
    binaryTree->InorderTraversal();
  //  binaryTree->PreorderTraversal();
  //  binaryTree->PostorderTraversal();
    
    if('a' > 'b')
        std::cout << "a is greater than b";
    else
        std::cout << "b is greater than a";
    
    return 0;
}


BinaryTree* createBinaryTree()
{
    BinaryTree* root = new BinaryTree(50);
    
    root->InsertNode(10);
    root->InsertNode(5);
    root->InsertNode(20);
    root->InsertNode(8);
 /*   root->InsertNode(100);
    root->InsertNode(40);
    root->InsertNode(6);
    root->InsertNode(4);
    root->InsertNode(70);*/
    
    return root;
    
}
