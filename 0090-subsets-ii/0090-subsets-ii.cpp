class Solution {
public:
vector<vector<int>>res;
void dfs(int curr,vector<int>&subset,vector<int>&nums){
    res.push_back(subset);
    for(int i=curr;i<nums.size();i++){
        if(i>curr && nums[i]==nums[i-1]) continue;
        subset.push_back(nums[i]);
        dfs(i+1,subset,nums);
        subset.pop_back();
    }

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subset;
        sort(nums.begin(),nums.end());
        dfs(0,subset,nums);
        return res;
    }
};