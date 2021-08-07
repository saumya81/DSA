class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
         stack<long long> s;
        vector<long long> v(n);
        s.push(arr[n-1]);
        v[n-1]=-1;
        //Here you have to do i--
        for(int i=n-2;i>=0;i--)
        {
          //pop the element fronm stack until the st.yop() will have greater element than arr[i] 
            while(s.empty()==false && s.top()<arr[i])
                s.pop();
            //stack element are in decreasing fashion
            if(s.empty()==true)
            {
                s.push(arr[i]);
                v[i]=-1;
             }
            else if(s.empty()==false)
            {   
                v[i]=s.top();
                s.push(arr[i]);
            }
        }
        return v;
    }
};
