/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26


Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/


#include <sstream>

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
       if(s == "")
        return 0;
       int evaluationArray[s.length() + 1];
      
       evaluationArray[0] = 1;
       
       if(canDecode(s.substr(0,1)))
       {
           evaluationArray[1] = 1;
       }
       else
       {
           evaluationArray[1] = 0;
       }
       
      int  i =1;
      for(i = 1; i < s.length(); i++)
      {
            bool singleCharDecode = canDecode(s.substr(i,1));
            bool doubleCharDecode = canDecode(s.substr(i-1, 2));
            
            if(singleCharDecode && doubleCharDecode)
            {
                evaluationArray[i+1] = evaluationArray[i] + evaluationArray[i-1]; 
            }
            else if(singleCharDecode)
            {
                evaluationArray[i+1] = evaluationArray[i];
            }
            else if(doubleCharDecode)
            {
                evaluationArray[i+1] = evaluationArray[i-1];            
            }
            else
            {
                evaluationArray[i+1] = 0;
            }        
        }
        
        return evaluationArray[s.length()];
        
    }
    
    bool canDecode(string num)
    {
        if(num.length() == 1)
        {
            if(num[0] == '0')
                return false;
            return true;                
        }
        else 
        {
            if(num[0] != '1' && num[0] != '2')
                return false;
            
            int val;
            
            stringstream(num) >> val;
            if(val > 26)
                return false;
        }
        return true;
        
    }
};