/**

Minimum Depth of a binary tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node 
down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
        if(root == NULL)
            return 0;
            
        int left = minDepth(root->left) + 1;
        int right = minDepth(root->right) + 1;
        
        if(left == 1 || right == 1)
            return left>right? left:right;
        
        return left < right ? left:right;


        
    }
};