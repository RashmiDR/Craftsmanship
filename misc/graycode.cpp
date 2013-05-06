/*

Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.


*/

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> graycodes;
        vector<int>::iterator iter;
        if(n < 0)
            return graycodes;
        if(n == 0)
            graycodes.push_back(0);
        else if(n >= 1)
        {
            graycodes.push_back(0);
            graycodes.push_back(1);
        }
        
        
        //For each of number within the vector, multiplying by next power of 2
        // in the reverse order will continue to add numbers with just one bit chnage
        int bitPos = 1;
        while(bitPos < n)
        {
            int size = graycodes.size();
            for(int i = size-1; i >=0; i--)
            {
                graycodes.push_back(graycodes[i] + pow(2, bitPos));
            }
                
            bitPos++;
            
        }
        return graycodes;        
        
    }
};