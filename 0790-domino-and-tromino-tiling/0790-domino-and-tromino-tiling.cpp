class Solution {
public:
    int numTilings(int n) {
        vector<long long>dp(n+2,1);
        dp[1]=1;
        dp[2]=2;
        int mod=1e9+7;
        for(int i=3;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%mod;
        }
        return dp[n];
    }
};