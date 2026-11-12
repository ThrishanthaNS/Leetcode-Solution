class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene==endGene) return 0;
        unordered_set<string>s(bank.begin(),bank.end());
        if(!s.count(endGene)) return -1;
        queue<pair<string,int>>q;
        q.push({startGene,0});
        unordered_set<string>visited;
        string valid="ACGT";
        while(!q.empty()){
            auto [curr,count]=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                char original=curr[i];
                for(char c:valid){
                    if (original==c) continue;
                    curr[i]=c;
                    if(s.count(curr) && !visited.count(curr)){
                        visited.insert(curr);
                        if(curr==endGene) return count+1;
                        q.push({curr,count+1});
                    }
                    curr[i]=original;
                }
            }
        }
        return -1;
    }
};