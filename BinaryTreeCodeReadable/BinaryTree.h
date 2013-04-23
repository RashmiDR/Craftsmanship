//
//  binaryTree.h
//  trees
//
//  Created by Rashmi Devarahalli on 3/10/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#ifndef __trees__binaryTree__
#define __trees__binaryTree__

#include <iostream>

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    

    BinaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


class BinaryTree
{
protected:
    BinaryTreeNode *root;
   
public:
    BinaryTree(int data)
    {
        root = new BinaryTreeNode(data);
    }
    BinaryTree(int *sortedArray, int arrayLength);
    bool IsEmpty();
    void InorderTraversal();
    void PreorderTraversal();
    void PostorderTraversal();
    int getHeight(BinaryTreeNode *node);
    int GetNodesCount();
    int GetLeafCount();
        void Delete(int key);
    void NonrecursiveInorder();
    void NonrecursivePreorder();
    void NonrecursivePostorder();
    void BreadthFirstSearch();
    void DepthFirstSearch();
    void LevelPrint();
    void ReverseLevelPrint();
    bool IsBalanced();
    //BinaryTreeNode* CreateBinaryTree(int *sortedArray, int arrayLength);
    
    
private:
    void inorder(BinaryTreeNode *node);
    void preorder(BinaryTreeNode *node);
    void postorder(BinaryTreeNode *node);
    int nodeCount(BinaryTreeNode *node);
    int leafCount(BinaryTreeNode *node);
    void destroy(BinaryTreeNode* node);
    void insert(int data);
    BinaryTreeNode* createNode(int data);
    void deleteFromTree(BinaryTreeNode *node);
    void printbylevel(BinaryTreeNode* node, int level);
    int maxDepth(BinaryTreeNode *node);
    int minDepth(BinaryTreeNode *node);
    BinaryTreeNode* constructBinaryTreeFromSortedArray(int *a, int begin, int end);
    
    
    
    
};


#endif /* defined(__trees__binaryTree__) */
