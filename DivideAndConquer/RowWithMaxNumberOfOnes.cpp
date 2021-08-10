#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int first(vector<int> arr ,int low,int high)
    {
        while(high >= low) 
        { 
            // Get the middle index 
            int mid = low + (high - low)/2; 
        
          
            if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1) 
                return mid; 
        
           
            else if (arr[mid] == 0) 
               low=mid+1;
            
            // If element is not first 1, recur for left side 
            else
                high=mid-1;
        } 
    return -1; 
        
    }
	int rowWithMax1s(vector<vector<int> > mat, int R, int C) {
	    int max_row_index = -1, max = -1; 

    int i, index; 
    for (i = 0; i < R; i++) 
    { 
        index = first (mat[i], 0, C-1); 
        if (index != -1 && C-index > max) 
        { 
          //as that is the first occurence of one and before that will be 0 so we subtract length of row with the first occurance
            max = C - index; 
            max_row_index = i; 
        } 
    } 

    return max_row_index; 
	}

};

2ns approach with m+n complexity 
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int i=0;
	    int j=m-1;
	    int maxRow=-1;
	    
	    while(i<n && j>=0)
	    {
	        if(arr[i][j]==1)
	        {
	            maxRow=i;
	            j--;
	        }
	        else
	        i++;
	    }
	    return maxRow;
	}

};

