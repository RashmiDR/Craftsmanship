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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> levelNodes;
        vector<vector<int>> result;
        queue<TreeNode*> bfsQueue;
        TreeNode *node;
        
        
        if(root != NULL)
            bfsQueue.push(root);
        
        while(!bfsQueue.empty())
        {
            int initialSize = bfsQueue.size();
            for(int i =0; i< initialSize; i++)
            {
                node = bfsQueue.front();
                bfsQueue.pop();
            
                levelNodes.push_back(node->val);
            
                if(node->left)    
                    bfsQueue.push(node->left);
                if(node->right)
                    bfsQueue.push(node->right);                            
            } 
            
            result.push_back(levelNodes);
            levelNodes.clear();
        }

        return result;   

    }
};