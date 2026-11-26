class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;
        vector<pair<int,int>>vec;
        int n=profits.size();
        for(int i=0;i<n;i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int idx=0;
        while(k--){
            while(idx<n && vec[idx].first<=w){
                pq.push(vec[idx++].second);
            }
            if(pq.empty()){
                return w;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};