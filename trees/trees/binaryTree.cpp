//
//  binaryTree.cpp
//  trees
//
//  Created by Rashmi Devarahalli on 3/10/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#include "binaryTree.h"
#include <stack>
#include <queue>
#include <utility>

using namespace std;


bool BinaryTree::IsEmpty()
{
    return (root == NULL);
}

void BinaryTree::InorderTraversal()
{
    inorder(root);
}

void BinaryTree::PreorderTraversal()
{
    preorder(root);
}

void BinaryTree::PostorderTraversal()
{
    postorder(root);
}

void BinaryTree::inorder(BinaryTreeNode *node)
{
    if(node != NULL)
    {
        inorder(node->left);
        cout << node->data << endl;
        inorder(node->right);
    }
    cout << endl;
}

void BinaryTree::preorder(BinaryTreeNode *node)
{
    if(node != NULL)
    {
        cout << node->data << endl;
        preorder(node->left);       
        preorder(node->right);
    }
    cout << endl;
}
void BinaryTree::postorder(BinaryTreeNode *node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << endl;
    }
    cout << endl;
    
}

int BinaryTree::GetNodesCount()
{
    return nodeCount(root);
}


int BinaryTree::nodeCount(BinaryTreeNode *node)
{
    if(node == NULL)
        return 0;
    else
        return 1 + nodeCount(node->left) + nodeCount(node->right);
}



int BinaryTree::GetLeafCount()
{
    return leafCount(root);
}

int BinaryTree::leafCount(BinaryTreeNode *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return leafCount(node->left) + leafCount(node->right);
}

int BinaryTree::getHeight(BinaryTreeNode *node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return 1+ max(getHeight(node->left), getHeight(node->right));
    }
    
}


void BinaryTree::NonrecursiveInorder()
{
    BinaryTreeNode *node = root;
    stack<BinaryTreeNode*> stack;
    
    while(node != NULL || !stack.empty())
    {
        if(node!=NULL)
        {
            stack.push(node);
            node =node->left;
        }
        else
        {
            node = stack.top();
            stack.pop();
            cout << node->data << "\t";
            node= node->right;
        }
    }
    
    cout <<endl;   
    
}

void BinaryTree::NonrecursivePreorder()
{
    BinaryTreeNode* node = root;
    stack<BinaryTreeNode*> stack;
    
    while (node != NULL || !stack.empty())
    {
        if(node != NULL)
        {
            cout << node->data << "\t";
            stack.push(node);
            node = node->left;            
        }
        else
        {
            node = stack.top();
            stack.pop();
            node = node->right;
        }
    }    
}
void BinaryTree::NonrecursivePostorder()
{
    BinaryTreeNode *current = root;
    stack<pair<BinaryTreeNode*, int>> stack;
    int traversingLeftOrRight = 0;//0 for root, 1 for left, 2 for right
    pair<BinaryTreeNode*, int> stackItem;
    
    if(current == NULL)
    {
        cout << "the tree is empty" <<endl;
        return;
    }
    else
    {
        stack.push(make_pair(current, 1));
        current = current->left;
        while(!stack.empty())
        {
            if(current != NULL && traversingLeftOrRight == 0)
            {
                stack.push(make_pair(current, 1));
                current = current->left;
            }
            else
            {
                stackItem = stack.top();
                stack.pop();
                traversingLeftOrRight = stackItem.second;
                if(traversingLeftOrRight == 1)
                {
                    stack.push(make_pair(current, 2));
                    current = current->right;
                    traversingLeftOrRight = 0;
                }
                else
                {
                    cout << current->data;
                }               
            }
        }        
    }    
}

void BinaryTree::BreadthFirstSearch()
{
    BinaryTreeNode* current = root;
    queue<BinaryTreeNode*> queue;
    
    if(current != NULL)
    {
        queue.push(current);
    }
    while(!queue.empty())
    {
        current = queue.front();
        queue.pop();
        cout << current->data << "\t";
        
        if(current->left)
        {
            queue.push(current->left);
        }
        if(current->right)
        {
            queue.push(current->right);
        }
    }
    cout << "\n";
}

void BinaryTree::DepthFirstSearch()
{
    //Preorder, postorder or inorder should work
}

void BinaryTree::LevelPrint()
{
    int levels = getHeight(root);
    
    for(int level = 0; level < levels; level++)
    {
        printbylevel(root, level);
        cout << endl;
    }    
}

void BinaryTree::printbylevel(BinaryTreeNode* node, int level)
{
    if(node == NULL)
        return;
    if(level == 0)
    {
        cout << node->data << "\t";
        return;
    }
    else
    {
        printbylevel(node->left, level-1);
        printbylevel(node->right, level-1);        
    }   
}

//print the leaf nodes first, followed by the previous level and root node in the end
void BinaryTree::ReverseLevelPrint()
{
    int levels = getHeight(root);
    
    for(int level = levels -1; level >= 0 ; level--)
    {
        printbylevel(root, level);
        cout << endl;
    }   
}


/*Implement a function to check if a tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.
 */

bool BinaryTree::IsBalanced()
{
    int maxLeafNodeDepth = maxDepth(root);
    int minLeafNodeDepth = minDepth(root);
    
    if(maxLeafNodeDepth - minLeafNodeDepth > 1)
    {
        return false;
    }
    return true;

}

int BinaryTree::maxDepth(BinaryTreeNode *node)
{
    if(node == NULL)
        return 0;
    else
        return max(maxDepth(node->left), maxDepth(node->right))+1;
}


int BinaryTree::minDepth(BinaryTreeNode *node)
{
    if(node == NULL)
        return 0;
    else
        return min(minDepth(node->left), minDepth(node->right))+1;       
    
}

//Construct Binary tree from sorted array

BinaryTree::BinaryTree(int *sortedArray, int arrayLength)
{
    root = constructBinaryTreeFromSortedArray(sortedArray, 0, arrayLength-1);
    
}

BinaryTreeNode* BinaryTree::constructBinaryTreeFromSortedArray(int *a, int begin, int end)
{
    if(a == NULL || begin > end)
    {
        return NULL;
    }
    int mid = (begin + end)/2;
    BinaryTreeNode *root = new BinaryTreeNode(a[mid]);
    root->left = constructBinaryTreeFromSortedArray(a, begin, mid-1);
    root->right = constructBinaryTreeFromSortedArray(a, mid+1, end);
    return root;
    
}






