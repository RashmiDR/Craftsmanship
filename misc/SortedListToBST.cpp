/**
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* root = NULL;
        if(head == NULL)
            return root;
        
        int count = 0;
        ListNode* currentNode = head;
        while(currentNode!=NULL)
        {
            currentNode = currentNode->next;
            count++;
        }
            
        root = constructBST(head, 0, count);
        return root;
    }
    
    TreeNode* constructBST(ListNode* node, int startIndex, int endIndex)
    {
        TreeNode* root = NULL;
        if(node == NULL)
            return root;
        if(startIndex < endIndex)
        {
            int mid = startIndex +(endIndex - startIndex)/2 ; 
            ListNode* head = node;
            int count = mid;
            while(count != 0)
            {
                count--;
                node = node->next;
            }
            root = new TreeNode(node->val);
            root->left = constructBST(head, startIndex,mid);
            root->right = constructBST(head,mid+1, endIndex);
        }
        return root;
    }
};