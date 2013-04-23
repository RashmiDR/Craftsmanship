/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
//Recursive 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) 
            return true;
        
        if(root->left == NULL && root->right == NULL)
            return true;

        return isMirrorSiblings(root->left, root->right);       
        
    }
    bool isMirrorSiblings(TreeNode* node1, TreeNode*node2)
    {
        if(node1 && node2)
        {
            if(node1->val == node2->val)
            {
                return (
                    isMirrorSiblings(node1->left, node2->right)
                        &&
                    isMirrorSiblings(node1->right, node2->left));
            }
            return false;
        }
        if(node1 || node2)
            return false;
        return true;
    }
};