
//here we use the formula of combination 
// as we can go only in 2 direction we have total number of ways if (row-1)+(col-1)=m+n-2=N;
//and total no. of ways is (row+col-2
//                                  C
//                                   row-1) 
//instead of row-1 we can rake col-1 also .

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++)
        {
            res=res*(N-r+i)/i;
        }
        return int(res);
    }
};
