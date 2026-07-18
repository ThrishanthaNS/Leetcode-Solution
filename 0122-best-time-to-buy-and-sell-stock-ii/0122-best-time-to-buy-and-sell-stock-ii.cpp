class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cash=0,hold=-prices[0];
        for(int x:prices){
            int newcash=max(cash,hold+x);
            int newhold=max(hold,cash-x);
            cash=newcash;
            hold=newhold;
        }
        return cash;
    }
};