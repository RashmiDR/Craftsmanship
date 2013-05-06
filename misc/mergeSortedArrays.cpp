/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int indexA = m-1;
        int indexB = n-1;
        int copyIndex = m+n-1;
        
        while(indexA >=0 && indexB >= 0)
        {
            if(A[indexA] > B[indexB])
            {
                A[copyIndex--] = A[indexA--];
            }
            else
            {
                A[copyIndex--] = B[indexB--];
            }         
        }
        while(indexB >= 0)
        {
            A[copyIndex--] = B[indexB--];   
        }
    }
};