class Solution {
public:
    int find(int x,vector<int>&parent){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj(n,0);
        vector<int>parent(n);
        iota(parent.begin(),parent.end(),0);
        for(auto& p:edges){
            adj[p[0]]++;
            adj[p[1]]++;
            int rooti=find(p[0],parent);
            int rootj=find(p[1],parent);
            if(rooti!=rootj) parent[rooti]=rootj;
        }
        int completeconnected=0;
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            parent[i]=find(i,parent);
            auto &p=mp[parent[i]];
            p.first+=1;
            p.second+=adj[i];
        }
        for(auto& [root,p]:mp){
            int vertices=p.first;
            int expected_edge=(vertices*(vertices-1));
            if(expected_edge==p.second) completeconnected++;
        }
        return completeconnected;;
    }
};