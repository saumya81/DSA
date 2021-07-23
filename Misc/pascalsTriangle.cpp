//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
            ans[i] = vector<int> (i + 1, 1);
        

        for(int i=1;i<numRows;i++)
            for(int j=1;j<i;j++)
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1]; 
        
        return ans;
    }
};
