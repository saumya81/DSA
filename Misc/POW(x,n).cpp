class Solution {
public:
    double positiveSolve(double x, long n)
    {
         if(n==0)
             return 1;
        else if(n%2==0)
            return positiveSolve(x*x,n/2);
        else
            return x*positiveSolve(x,n-1);
}
    double myPow(double x, int n) {
    long k=abs(n);
          double ans= positiveSolve(x,k);
        if(x==1||x==0)
            return x;
        if(n>0)
            return ans;
        else
            return double(1.0)/ans;
        
            
    }
};
