class Solution {
public:
    void processqueue(queue<pair<int,int>>&q,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int dr[]={1,0,0,-1};
        int dc[]={0,1,-1,0};
        int m=grid.size();
        int n=grid[0].size();
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(vis[r][c]) continue;
            vis[r][c]=1;
            for(int i=0;i<4;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0 && row<m && col>=0 && col<n ){
                    if(grid[row][col]==0 && !vis[row][col]){
                        q.push({row,col});
                    }
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[0][i]==0 && !vis[0][i]){
                q.push({0,i});
                processqueue(q,vis,grid);
            }
            if(grid[m-1][i]==0 && !vis[m-1][i]){
                q.push({m-1,i});
                processqueue(q,vis,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==0 && !vis[i][0]){
                q.push({i,0});
                processqueue(q,vis,grid);
            }
            if(grid[i][n-1]==0 && !vis[i][n-1]){
                q.push({i,n-1});
                processqueue(q,vis,grid);
            }
        }
        int ans=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0 &&!vis[i][j]){
                    q.push({i,j});
                    //cout<<i<<" "<<j<<"\n";
                    processqueue(q,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};