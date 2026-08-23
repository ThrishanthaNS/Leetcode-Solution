class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int>appear(upper+2,0);
        vector<vector<int>>ans;
        for(int x:nums){
            if(x<=upper)
                appear[x]=1;
        }
        appear[upper+1]=1;
        int start=lower,end=lower;
        for(int i=lower;i<=upper+1;i++){
            if(appear[i]){
                end=i;
                if(start!=end){
                    ans.push_back({start,end-1});
                }
                start=end+1;
            }
        }
        return ans;
    }
};