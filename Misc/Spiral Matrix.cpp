Question- https://leetcode.com/problems/spiral-matrix/
video link-https://www.youtube.com/watch?v=1ZGJzvkcLsA

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,down=n-1,left=0,right=m-1;
        int dir=0;
        vector<int> ans;
        while(top<=down && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                    ans.push_back(matrix[top][i]);
                    top+=1;

            }
           else if(dir==1)
            {
                for(int i=top;i<=down;i++)
                    ans.push_back(matrix[i][right]);
                    right-=1;

            }
           else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                    ans.push_back(matrix[down][i]);
                    down-=1;

            }
           else if(dir==3)
            {
                for(int i=down;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                    left+=1;

            }
            dir=(dir+1)%4;
        }
        return ans;

    }
};
