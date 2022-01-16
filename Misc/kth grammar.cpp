
question ->https://leetcode.com/explore/learn/card/recursion-i/253/conclusion/1675/

video solution-> https://www.youtube.com/watch?v=5P84A0YCo_Y&t=172s

class Solution {
public:
  
    int kthGrammar(int n, int k) {
       
       if(n==1 || k==1)
           return 0;
         int mid=pow(2,n-1)/2;
       if (k<=mid)
            return kthGrammar(n-1,k);
        else
            return !(kthGrammar(n-1,k-mid));

    }
};
