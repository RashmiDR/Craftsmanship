/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
  Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2 5
/ \ \
3 4 6

The flattened tree should look like:
1
\
2
\
3
\
4
\
5
\
6
 */
class Solution {
public:
    TreeNode* flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL)
            return NULL;
        
        if(root->left == NULL && root->right == NULL)
            return root;
        
        TreeNode* left_last = flatten(root->left);
        TreeNode* right_last = flatten(root->right);
        
        if(left_last && right_last)
        {
            left_last->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return right_last;            
        }
        if(left_last)
        {
            root->right = root->left;
            root->left = NULL;
            return left_last;            
        }
        root->left = NULL;
        return right_last;
        

    }
};