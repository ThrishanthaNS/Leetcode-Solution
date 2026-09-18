class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>ans(n+1,INT_MAX);
        for(auto vec:times){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        ans[k]=0;
        while(!pq.empty()){
            auto [dist,u]=pq.top();
            pq.pop();
            for(auto &[v,w]:adj[u]){
                int newcost=dist+w;
                if(ans[v]>newcost){
                    ans[v]=newcost;
                    pq.push({newcost,v});
                }
            }
        }
        int res=ans[1];
        for(int i=1;i<=n;i++){
            int x=ans[i];
            //cout<<x<<" ";
            if(x==INT_MAX && i!=k) return -1;
            res=max(res,x);
        }
        return res;
    }
};