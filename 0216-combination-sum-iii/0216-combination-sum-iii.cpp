class Solution {
public:
    vector<vector<int>>ans;
    void backtracking(int curr,int n,int sum,int k,vector<int>&vec){
        int s=vec.size();
        if(sum==n && s==k) {
            ans.push_back(vec);
            return;
        }
        if(sum>n || s>k ||curr>9) return;
        vec.push_back(curr);
        backtracking(curr+1,n,sum+curr,k,vec );
        vec.pop_back();
        backtracking(curr+1,n,sum,k,vec);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vec;
        backtracking(1,n,0,k,vec);
        return ans;
    }
};