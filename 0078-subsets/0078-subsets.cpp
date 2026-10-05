class Solution {
public:
vector<vector<int>>ans;
    void solve(int curr,vector<int>&nums,vector<int>&subset){
        if(curr==nums.size()){
            ans.push_back(subset);
            return;
        }
        solve(curr+1,nums,subset);
        subset.push_back(nums[curr]);
        solve(curr+1,nums,subset);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        solve(0,nums,subset);
        return ans;
    }
};