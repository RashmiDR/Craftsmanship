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

    map<int, int> inorderIndexMap;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int n, int offset) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
       
        if(inorder.size() != postorder.size())
            return NULL;
            
        buildInorderIndexHashMap(inorder);
        
        return buildBinaryTree(inorder, postorder, inorder.size(), 0);
        
        
    }
    
     TreeNode *buildBinaryTree(vector<int> &inorder, vector<int> &postorder, int n, int offset) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        

        
        int rootVal = postorder[n-1];
        
        TreeNode* root = new TreeNode(rootVal);
        
        
        int rootIndex = inorderIndexMap[postorder[n-1]] - offset;
        
        root->left = buildBinaryTree(inorder, postorder, rootIndex, offset);
        roor->right = buildBinaryTree(inorder + rootIndex+1, postorder+rootIndex, n-rootIndex-1, offset+rootIndex+1);
            
        return root;
        
    }
    
    void buildInorderIndexHashMap(vector<int> &inorder)
    {
       for(int i = 0; i < inorder.size(); i++)
       {
           inorderIndexMap[inorder[i]] = i;
       }
       
    }

};