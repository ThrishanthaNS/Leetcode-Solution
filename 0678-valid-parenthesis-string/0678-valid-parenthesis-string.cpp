class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string s,int i,int balance){
        if(balance<0) return false;
        if(i==s.size()){
            return balance==0;
        }
        if(dp[i][balance]!=-1){
            return dp[i][balance];
        }
        bool ans=false;
        if(s[i]=='('){
            ans=solve(s,i+1,balance+1);
        }
        else if(s[i]==')'){
            ans=solve(s,i+1,balance-1);
        }
        else{
            ans=solve(s,i+1,balance+1)||solve(s,i+1,balance-1)||solve(s,i+1,balance);
        }
        return dp[i][balance]=ans;
        

    }
    bool checkValidString(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(s,0,0);
    }
};