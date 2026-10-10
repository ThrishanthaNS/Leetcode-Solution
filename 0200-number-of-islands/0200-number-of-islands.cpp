class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numisland=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int di[]={0,0,-1,1};
        int dj[]={-1,1,0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1) continue;
                if(grid[i][j]=='0'){
                    vis[i][j]=1;
                    continue;
                }
                else{
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto[k,l]=q.front();
                        q.pop();
                        for(int idx=0;idx<4;idx++){
                            int dk=di[idx]+k;
                            int dl=dj[idx]+l;
                            if(dk>=0 && dk<m && dl>=0 && dl<n){                    
                                if(vis[dk][dl]==0 && grid[dk][dl]=='1'){
                                    vis[dk][dl]=1;
                                    q.push({dk,dl});
                                }
                            }
                        }
                    }
                    numisland++;
                }

            }
        }
        return numisland;
    }
};