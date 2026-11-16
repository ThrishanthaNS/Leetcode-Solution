class Solution {
public:
int f(int idx,int buy,int cap,vector<int>&price,vector<vector<vector<int>>>&dp){
    if(cap==0 || idx==price.size()) return 0;
    if(dp[idx][buy][cap]!=-1){
        return dp[idx][buy][cap];
    }
    if(buy){
        return dp[idx][buy][cap]= max(-price[idx]+f(idx+1,0,cap,price,dp),
                    0+f(idx+1,1,cap,price,dp));
    }
    return dp[idx][buy][cap]= max(price[idx]+f(idx+1,1,cap-1,price,dp),
                0+f(idx+1,0,cap,price,dp));
}
    int maxProfit(vector<int>& price) {
        int n=price.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,price,dp);
    }
};