class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>adjlist;
    double dfs(string src,string dest,unordered_set<string>&vis){
        if(src==dest) return 1.0;
        vis.insert(src);
        for(auto&[next,weight]:adjlist[src]){
            if(vis.count(next)) continue;
            double ans=dfs(next,dest,vis);
            if(ans!=-1.0){
                return weight*ans;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=values.size();
        for(int i=0;i<n;i++){
            string src=equations[i][0],dest=equations[i][1];
            double w=values[i];
            adjlist[src].push_back({dest,w});
            adjlist[dest].push_back({src,1/w});
        }
        vector<double>ans;
        for(const auto &p:queries){
            string src=p[0],dest=p[1];
            if(!adjlist.count(src)||!adjlist.count(dest)){
                ans.push_back(-1.0);
                continue; 
            }
            unordered_set<string>vis;
            ans.push_back(dfs(src,dest,vis));
        }
        return ans;
    }
};