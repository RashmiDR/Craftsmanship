//
//  BST.cpp
//  trees
//
//  Created by Rashmi Devarahalli on 4/18/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#include "BST.h"



void BinaryTree::DestroyTree()
{
    destroy(root);
}

void BinaryTree::destroy(BinaryTreeNode *node)
{
    if(node == NULL)
        return;
    else if(node->left == NULL && node->right == NULL)
    {
        delete node;
        node = NULL;
    }
    destroy(node->left);
    destroy(node->right);
}



void BinaryTree::InsertNode(int data)
{
    insert(data);
    
}


void BinaryTree::insert(int data)
{
    BinaryTreeNode *currentNode = root;
    BinaryTreeNode *prevNode = NULL;
    if(root == NULL)
    {
        root = createNode(data);
        return;
    }
    
    while(currentNode)
    {
        prevNode = currentNode;
        if(data < currentNode->data)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
    
    currentNode = createNode(data);
    if(data < prevNode->data)
    {
        prevNode->left = currentNode;
    }
    else
    {
        prevNode->right = currentNode;
    }
    
    
}

BinaryTreeNode* BinaryTree::createNode(int data)
{
    BinaryTreeNode *newNode = new BinaryTreeNode(data);
    if(newNode != NULL)
    {
        return newNode;
    }
    return NULL;
    
}

bool BinaryTree::Search(int key)
{
    BinaryTreeNode* node = root;
    
    
    while(node != NULL)
    {
        if(key == node->data)
        {
            return true;
        }
        else if(key < node->data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return false;
}

void BinaryTree::Delete(int key)
{
    BinaryTreeNode *node = root;
    bool found = false;
    
    while(node!= NULL)
    {
        if(key == node->data)
        {
            found = true;
            break;
        }
        else
        {
            if(key < node->data)
            {
                node = node->left;
            }
            else if(key > node->data)
            {
                node = node->right;
            }
        }
    }
    
    if(found == true)
    {
        deleteFromTree(node);
    }
    else
    {
        cout << "Key to be deleted not found in the tree" << endl;
    }
    
}

void BinaryTree::deleteFromTree(BinaryTreeNode *node, bool isRoot = false)
{
    BinaryTreeNode *temp, *rightMostNode, *currentNode, *prevNode = NULL;
    
    if(node == NULL)
    {
        cout << "Node to be deleted is NULL" << endl;
    }
    if(node->left == NULL && node->right == NULL)
    {
        temp = node;
        node = NULL;
        delete temp;
    }
    else if(node->left == NULL)
    {
        temp = node;
        node = node->right;
        delete temp;
    }
    else if(node->right == NULL)
    {
        temp = node;
        node =node->left;
        delete temp;
    }
    else
    {
        //When the node to be deleted has both right and left node,
        //you need to find the appropriate node to replace the node to be deleted.
        //Replace with node found from (Go left and find its right most)
        //or with node from(Go right and find its left most)
        //Below, I have followed 'Go left and find its right most'
        rightMostNode = NULL;
        
        //Go to the left node
        currentNode = node->left;
        
        
        //Find the rightmost of the left node
        while(currentNode != NULL)
        {
            prevNode = currentNode;
            rightMostNode = currentNode;
            currentNode = currentNode->right;
        }
        
        //Copy the contents of the current node to node and delete the current node, so that right tree of the node to be deleted remains intact.
        rightMostNode->data = node->data;
        
        //check if the rightmost node has left child
        if(rightMostNode->left != NULL)
        {
            prevNode->right = currentNode->left;
        }
        else
        {
            rightMostNode->left = node->left;
            rightMostNode->right = node->right;
        }
        delete node;
        
    }
    
}
