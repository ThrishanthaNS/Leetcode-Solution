class Solution {
public:
vector<vector<int>> ans;
void backtrack(int n,int k,int curr,vector<int>& res){
    if(res.size()==k){
        ans.push_back(res);
        return;
    }

    for(int i=curr+1;i<=n;i++){
        res.push_back(i);
        backtrack(n,k,i,res);
        res.pop_back();
    }

}
    vector<vector<int>> combine(int n, int k) {
        vector<int>res;
        backtrack(n,k,0,res);
        return ans;
    }
};