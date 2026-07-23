class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<int>&candidates,int target,int idx,vector<int>&res){
        if(target==0){
            ans.push_back(res);
            return;
        }
        if(target<0) return;
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) return;
            res.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1,res);
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>res;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,res);
        return ans;

    }
};