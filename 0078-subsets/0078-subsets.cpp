class Solution {
public:
vector<vector<int>>ans;
    void dfs(vector<int>&nums,int i,vector<int>&vec){
        if(i==nums.size()) {
            return;
        }
        dfs(nums,i+1,vec);
        vec.push_back(nums[i]);
        ans.push_back(vec);
        dfs(nums,i+1,vec);
        vec.pop_back();

       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        dfs(nums,0,vec);
        ans.push_back({});
        return ans;
    }
};