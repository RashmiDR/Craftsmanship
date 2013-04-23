Given n non-negative integers representing an elevation map where 
the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.


class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    int forwardRainWaterCollected[n];
    int backwardRainWaterCollected[n];
    int totalWaterCollected = 0;
    int  i =0;
    
    int max = A[i];
    
    for(i = 0; i<n; i++)
    {
       if(A[i] > max)
       {
           max = A[i];
       }
       forwardRainWaterCollected[i] = max - A[i];
    }
    
    
    max = A[n-1];
    for(i = n-1; i>=0; i--)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
        backwardRainWaterCollected[i] = max - A[i];
    }
    
    //Find minimum in both arrays, sum of all the mins is the total water collected
    for(i = 0; i <n; i++)
    {
        totalWaterCollected += 
            min(forwardRainWaterCollected[i], backwardRainWaterCollected[i]);        
    }
    
    return totalWaterCollected;
    }

};



class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int totalWater = 0;
        int totalObstacles = 0;
        int inBetweenValues = 0;
        int i = 0, j=0;
        bool iSet = false;
        int lastGoodValueIndex = 0;
        
        if(n == 1)
        {
            return 0;
        }
        while(i < n)
        {
            if(A[i] > 0)
            {
                for (j = i+1; j < n; j++)
                {
                    if(A[j] >= A[i])
                    {
                        totalWater+= A[i]*(j-i-1);
                        totalObstacles+=inBetweenValues;                       
                        inBetweenValues = 0;
                        i = j;
                        iSet = true;
                        lastGoodValueIndex = i;
                        break;
                    }
                    else
                    {
                        inBetweenValues+= A[j];  
                    }
                } 

            }
            if(iSet == false)
            {
                inBetweenValues = 0;
                i++;
            }
            else
                iSet = false;
            
         }

        i = n-1;
        inBetweenValues =0;
        iSet = false;
        while(i > lastGoodValueIndex)
        {
            if(A[i] > 0)
            {
                for(j = i -1; j>= lastGoodValueIndex; j--)
                {
                    if(A[j] >= A[i])
                    {
                        totalWater+= A[i] * (i - j -1);
                        totalObstacles+=inBetweenValues;
                        inBetweenValues = 0;
                        i = j;
                        iSet = true;
                        break;  
                        
                    }
                    else
                    {
                        inBetweenValues+= A[j];
                    }
                }
            }
            if(iSet)
                iSet = false;
            else
            {
                inBetweenValues = 0;
                i--; 
            }
               
        }
        
      return totalWater - totalObstacles;       
        
    }
    

};