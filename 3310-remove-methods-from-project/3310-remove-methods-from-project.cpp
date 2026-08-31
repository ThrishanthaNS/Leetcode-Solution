class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>sus(n,0),res;
        queue<int>q;
        q.push(k);
        vector<vector<int>>adjlist(n);
        for(auto p:invocations){
            adjlist[p[0]].push_back(p[1]);
        }
        while(!q.empty()){
            int p=q.front();
            q.pop();
            if(sus[p]) continue;
            sus[p]=1;
            for(int x:adjlist[p]){
                q.push(x);
            }
        }
        int isremove=1;
        for(auto p:invocations){
            if(!sus[p[0]] && sus[p[1]]){
                isremove=0;
                break;
            }
        }
        if(isremove){
            for(int i=0;i<n;i++){
                if(!sus[i]) res.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                res.push_back(i);
            }
        }
        return res;
    }
};