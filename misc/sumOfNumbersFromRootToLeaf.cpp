/**
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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
            
        TreeNode *node = root;
        int totalSum = 0;
        
        if(root == NULL)
            return 0;
            

        
        if(root->left == NULL && root->right == NULL)
            totalSum += root->val;
        if(root->left!= NULL)
        {
             totalSum += root->val * 10 + sumNumbers(root->left);
        }

        if(root->right != NULL)
            totalSum += root->val * 10 + sumNumbers(root->right);
        return totalSum;    
    }
       
};