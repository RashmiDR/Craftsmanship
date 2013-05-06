/**
Reverse Linked list between m &n indices

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(head == NULL)
            return  NULL;
            
        if(m == n)
            return head;
            
        ListNode *temp = NULL, *startNode = head, *prevNodeToStart = head; 
        ListNode *node = head, *nextNode = NULL, *prevNode = NULL;
        int count =1;
        while(true)
        {
            if(count >= m && count < n)
            {
                if(count == m)
                {
                    prevNodeToStart = prevNode;
                    startNode = node;                    
                }
                    
                
                nextNode = node->next;
                node->next = prevNode;
                prevNode = node;
                node = nextNode;
                
            }
            else if(count < m)
            {
                prevNode = node;
                node = node->next;
                
            }
            else if(count == n)
            {
                startNode->next = node->next;
                if(prevNodeToStart)
                    prevNodeToStart->next = node;
                node->next = prevNode;
                break;
                
                
            }
            count++;
            
        }
        if(m == 1)
        {
            return node; 
        }
        return head;
           
    }
};