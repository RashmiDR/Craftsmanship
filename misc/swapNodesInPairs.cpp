/**
Swap Nodes In Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space.
 You may not modify the values in the list, only nodes itself can be changed.
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//Iterative solution 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *startNode = NULL, *temp = NULL;
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
            return head;
        else
            startNode = head->next;
        

        swap(head, NULL);
            

        return startNode;
    }
    
    void swap(ListNode* node, ListNode *prevPair)
    {
        ListNode *firstNode = NULL, *secondNode = NULL;
        ListNode *nextPair = NULL;
        if(node == NULL)
            return;
       
        
        firstNode = node;
        secondNode = node->next;
        while(secondNode)
        {
            nextPair = secondNode->next;
            secondNode->next = firstNode;
            if(nextPair)
            {
                if(nextPair->next)
                    firstNode->next = nextPair->next;  
                else
                    firstNode->next = nextPair;
            
                firstNode = nextPair;
                secondNode = nextPair->next;
            }
            else
            {
                firstNode->next = NULL;
                break;
            }
        }
    }
};

//Recursive solution
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        
        ListNode *nextNode = NULL, *nextPair = NULL;
        if(head == NULL)
            return NULL;
        
        nextNode = head->next;
        if(nextNode)
        {
            nextPair = nextNode->next;
            nextNode->next = head;
            head = nextNode;
            head->next->next = swapPairs(nextPair);
            return head;
        }
        return head;        
    }    

};