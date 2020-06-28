class Solution {
public:
    int n,m;
    vector<vector<int> > vis;
    vector<vector<int> > avoid;
    
    bool chk(int i,int j) {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }
    
    void dfs(int i,int j,vector<vector<char>>& board) {
        
        vis[i][j]=1;
        avoid[i][j]=1;
        
        if(chk(i-1,j) && !vis[i-1][j] && board[i-1][j]=='O') {
            dfs(i-1,j,board);
        }
        if(chk(i,j+1) && !vis[i][j+1] && board[i][j+1]=='O') {
            dfs(i,j+1,board);
        }
        if(chk(i+1,j) && !vis[i+1][j] && board[i+1][j]=='O') {
            dfs(i+1,j,board);
        }
        if(chk(i,j-1) && !vis[i][j-1] && board[i][j-1]=='O') {
            dfs(i,j-1,board);
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        n=board.size();
        m=board[0].size();
        
        vis.clear();
        avoid.clear();
        vis.resize(n,vector<int>(m,0));
        avoid.resize(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || i==n-1 || j==0 || j==m-1) {
                    if(board[i][j]=='O' && vis[i][j]==0) {
                        dfs(i,j,board);
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='O' && avoid[i][j]==0)
                    board[i][j]='X';
            }
        }
    }
};
