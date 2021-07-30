class Solution{
public:

void solve(vector<string> &board,vector<vector<int>> &ans,int col,int n,vector<int> lR,
vector<int> uD,vector<int> dD)
    {
        if(col==n)
        {
            vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Q')
                    v.push_back(j + 1);
            }
        }
        ans.push_back(v);
      
            
        }
        for(int row=0;row<n;row++){
        if(lR[row]==0 && uD[n-1+col-row]==0 && dD[row+col]==0)
        {
            board[row][col]='Q';
            lR[row]=1;
            uD[n-1+col-row]=1;
            dD[row+col]=1;
            
            solve(board,ans,col+1,n,lR,uD,dD);
           
            board[row][col]='.';
            lR[row]=0;
            uD[n-1+col-row]=0;
            dD[row+col]=0;
            
        }
        
        }
    }
    vector<vector<int>> nQueen(int n) {
       vector<vector<int>> ans;
        vector<int> lR(n,0);
        vector<int> uD(2*n-1,0);
        vector<int> dD(2*n-1,0);
        string s(n,'.');
        vector<string> board(n);
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
      
        solve(board,ans,0,n,lR,uD,dD);
     
        return ans;
       
    }
};
