class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int target,int curr,const vector<int>& candidate,vector<int>& res){
        if(target==0) {
            ans.push_back(res);
            return;
        }
        if(target<0)return;
        if(curr==candidate.size()) return;
        dfs(target,curr+1,candidate,res);
        target-=candidate[curr];
        res.push_back(candidate[curr]);
        dfs(target,curr,candidate,res);
        res.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        dfs(target,0,candidates,res);
        return ans;
    }
};