class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
       int n=items.size();
        vector<int>factor(n),price(n);
        vector<int>bonus(n,0);
        for(int i=0;i<n;i++){
            factor[i]=items[i][0];
            price[i]=items[i][1];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && factor[j]%factor[i]==0){
                    bonus[i]++;
                }
            }
        }
        int minprice=*min_element(price.begin(),price.end());
        int base=budget/minprice;
        vector<int>dp(budget+1,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int b=budget;b>=price[i];b--){
                if(dp[b-price[i]]==-1){
                    continue;
                }
                dp[b]=max(dp[b],dp[b-price[i]]+1+bonus[i]);
            }
        }
        int ans=budget/minprice;
        for(int spent=0;spent<=budget;spent++){
            if(dp[spent]==-1)  continue;
            ans=max(ans,dp[spent]+(budget-spent)/minprice);
        }
        return ans;
    }
};