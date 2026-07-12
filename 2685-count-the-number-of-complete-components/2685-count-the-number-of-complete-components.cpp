class Solution {
public:
    int find(int x,vector<int>&parent){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>parent(n);
        iota(parent.begin(),parent.end(),0);
        for(auto& p:edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
            int rooti=find(p[0],parent);
            int rootj=find(p[1],parent);
            if(rooti!=rootj) parent[rooti]=rootj;
        }
        vector<int>vis(n+1,0);
        unordered_set<int>connected;
        for(int i=0;i<n;i++){
            parent[i]=find(parent[i],parent);
            connected.insert(parent[i]);
        }
        int completeconnected=0;
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            auto &p=mp[parent[i]];
            p.first+=1;
            p.second+=adj[i].size();
        }
        for(int x:connected){
            int vertices=mp[x].first;
            int expected_edge=(vertices*(vertices-1));
            //cout<<x<<" "<<vertices<<" "<<expected_edge<<" "<<mp[x].second<<"\n";
            if(expected_edge==mp[x].second) completeconnected++;
        }
        return completeconnected;;
    }
};