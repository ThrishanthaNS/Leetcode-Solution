class Solution {
public:
    void dfs(vector<vector<int>>&adj,int s,vector<int>& sus){
        if(sus[s]==1) return;
        sus[s]=1;
        for(int x:adj[s]){
           dfs(adj,x,sus);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>sus(n,0),ans;
        vector<vector<int>>adj(n);
        bool isremove=true;
        for(auto &p:invocations){
            adj[p[0]].push_back(p[1]);
        }
        dfs(adj,k,sus);
        for(auto &p:invocations){
            if(!sus[p[0]] && sus[p[1]]) {
                isremove=false;
                break;
            }
        }
        if(!isremove){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            if(sus[i]) continue;
            ans.push_back(i);
        }
        return ans;
    }
};