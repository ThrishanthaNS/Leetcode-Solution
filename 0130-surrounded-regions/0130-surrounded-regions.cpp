class Solution {
public:
   void processqueue(queue<pair<int,int>>&q,vector<vector<char>>& board,vector<vector<int>>& vis){
        int dr[]={1,0,0,-1};
        int dc[]={0,1,-1,0};
        int m=board.size();
        int n=board[0].size();
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(vis[r][c]) continue;
            vis[r][c]=1;
            for(int i=0;i<4;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0 && row<m && col>=0 && col<n ){
                    if(board[row][col]=='O' && !vis[row][col]){
                        q.push({row,col});
                    }
                }
            }
        }
   }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            }
            if(board[m-1][i]=='O'){
                q.push({m-1,i});
                
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
               
            }
        }
        processqueue(q,board,vis);
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};