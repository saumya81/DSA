class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int row=matrix.size();
        int col=matrix[0].size();
        bool coln=true;
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==1)
            coln=false;
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[0][j]=matrix[i][0]=1;
                }
            }
        }
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
               if(matrix[0][j]==1||matrix[i][0]==1)
               matrix[i][j]=1;
            }
        }
        if(coln=false)
        matrix[0][0]=1;
    }
};
