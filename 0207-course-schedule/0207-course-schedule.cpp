class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>count(n,0);
        unordered_map<int,unordered_set<int>>depend;
        queue<int>q;
        for(auto x:pre){
            count[x[0]]++;
            depend[x[1]].insert(x[0]);
        }
        for(int i=0;i<n;i++){
            if(count[i]==0) q.push(i);
        }
        if(q.empty()) return false;
        while(!q.empty()){
            int course=q.front();
            q.pop();
            for(int c:depend[course]){
                count[c]--;
                if(count[c]==0) q.push(c);
            }
            depend.erase(course);
        }
        for(int x:count){
            if(x!=0) return false;
        }
        return true;
        


    }
};