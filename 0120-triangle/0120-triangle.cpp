class Solution {
public:

int solve(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    if(i==triangle.size()-1){
        return triangle[i][j];
    }
    if(dp[i][j]!=INT_MAX) return dp[i][j];

    int left=solve(i+1,j,triangle,dp);
    int right=solve(i+1,j+1,triangle,dp);
    return 
        dp[i][j]=triangle[i][j]+min(left,right);
    
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++)
            dp[i]=vector<int>(triangle[i].size(),INT_MAX);
        int ans=solve(0,0,triangle,dp); 
        
        return ans;
    }
};