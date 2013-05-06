/**
Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?



 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeNode *node = NULL, *buggyNode1 = NULL, *buggyNode2 = NULL;
        queue<TreeNode*> bfsQueue;
        bool isLeftWrong = false, isRightWrong = false;
        
        if(root == NULL)
            return;
            
        bfsQueue.push(root);
    
        while(!bfsQueue.empty())
        {
            int size = bfsQueue.size();
            for(int  i = 0; i<size; i++)
            {
                node = bfsQueue.front();
                bfsQueue.pop();
                
                if(node->left)
                {
                    bfsQueue.push(node->left);
                    if(node->left->val > node->val)
                    {
                        isLeftWrong = true;
            //            buggyNode1 = node;
                    }  
                    else
                    {
                        isLeftWrong = false;
                    }
                }
                if(node->right)
                {
                    bfsQueue.push(node->right);
                    if(node->right->val < node->val)
                    {
                        isRightWrong = true;
                  //      buggyNode2 = node;
                    }
                    else
                    {
                        isRightWrong = false;
                    }
                }
                if(isLeftWrong && isRightWrong)
                {
                    buggyNode1 = node->left;
                    buggyNode2 = node->right;
                }
                else if(isLeftWrong)
                {
                    if(node != buggyNode2)
                        buggyNode1 = node;
                    buggyNode2 = node->left;
                    //buggyNode2 = node;
                }
                else if(isRightWrong)
                {
                    if(node != buggyNode2)
                        buggyNode1 = node;
                    buggyNode2 = node->right;
                    //buggyNode2 = node;
                }
                
                
                isLeftWrong = false;
                isRightWrong = false;
                    
            }
        }
        
        if(buggyNode1 && buggyNode2)
        {
            int temp = buggyNode1->val;
            buggyNode1->val = buggyNode2->val;
            buggyNode2->val = temp;
        }
        else if(buggyNode1)
        {
           // node
        }
    }
       
    
};