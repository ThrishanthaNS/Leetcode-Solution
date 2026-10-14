class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        vector<int>digits(num,9);
        int total=num*9;
        if(sum>total){
            return "";
        }
        int idx=num-1;
        while(total>sum){
            digits[idx]--;
            total--;
            if(digits[idx]==0){
                idx--;
            }
        }
        string ans="";
        for(int x:digits){
            ans+=(x+'0');
        }
        return ans;
    }
};