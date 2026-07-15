class Solution {
public:
    int maxProfit(vector<int>& price ,int fee) {
        int n=price.size();
        if(n==0) return 0;
        int cash=0,hold=-price[0];
        for(int i=0;i<n;i++){
            int newcash=max(cash,hold+price[i]-fee);
            int newhold=max(hold,cash-price[i]);
            cash=newcash;
            hold=newhold;
            
        }
        return cash;
    }
};