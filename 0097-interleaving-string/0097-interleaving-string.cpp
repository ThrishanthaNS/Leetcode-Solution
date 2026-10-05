class Solution {
public:
    bool solve(string s1, string s2, string s3,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size()&& j==s2.size()) return true;
        if(dp[i][j]!=100) return dp[i][j];
        dp[i][j]=(s1[i]==s3[i+j] && solve(s1,s2,s3,i+1,j,dp))||
                 (s2[j]==s3[i+j] && solve(s1,s2,s3,i,j+1,dp));

        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,100));
        if(n1+n2!=s3.size()) return false;
        return solve(s1,s2,s3,0,0,dp);
    }
};