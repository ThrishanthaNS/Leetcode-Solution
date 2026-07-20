class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),total=m*n;
        vector<int>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans.push_back(grid[i][j]);
            }
        }
        k=k%total;
        k=total-k;
        k=k%total;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=ans[k];
                k=(k+1)%total;
            }
        }
              
        return grid;
    }
};