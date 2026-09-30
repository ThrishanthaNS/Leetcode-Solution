class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>res,course(n,0),count(n,0);
        unordered_map<int,vector<int>>mp;
        for(auto &p:prerequisites){
            count[p[0]]++;
            mp[p[1]].push_back(p[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(count[i]==0) q.push(i);
        }
        if(q.empty()) return {};
        while(!q.empty()){
            int c=q.front();
            q.pop();
            res.push_back(c);
            for(int x:mp[c]){
                count[x]--;
                if(count[x]==0) q.push(x);
            }
            mp.erase(c);
        }
        if(res.size()!=n) return {};
        return res;
    }
};