complexity=32*Rlog(C)
  ---------------------------------

class Solution{   
public:
int countSmallerThanOrEqualTo(vector<int> arr,int mid)
{
    int l=0;
    int h=arr.size()-1;
    while(l<=h)
    {
        int m=(l+h)>>1;
        if(arr[m]<=mid)
        l=m+1;
        else
        h=m-1;
    }
    return l;
}
    int median(vector<vector<int>> &matrix, int r, int c){
        int h=1e9;
        int l=1;
        while(l<=h)
        {
            int mid=(l+h)>>1;
            int cnt=0;
            for(int i=0;i<r;i++)
            {
                cnt+=countSmallerThanOrEqualTo(matrix[i],mid);
            }
            if(cnt<=(r*c)/2)
            l=mid+1;
            else
            h=mid-1;
        }
        return l;
    }
};
