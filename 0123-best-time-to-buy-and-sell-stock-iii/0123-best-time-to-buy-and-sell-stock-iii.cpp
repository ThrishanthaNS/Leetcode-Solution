class Solution {
public:
    int maxProfit(vector<int>& price) {
        int buy1=INT_MIN;
        int sell1=0;
        int buy2=INT_MIN;
        int sell2=0;
        for(int x:price){
            buy1=max(buy1,-x);
            sell1=max(sell1,buy1+x);
            buy2=max(buy2,sell1-x);
            sell2=max(sell2,buy2+x);
        }
        return sell2;
    }
};