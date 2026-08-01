class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int s=intervals[0][0],e=intervals[0][1];
        int i=0;
        while(i<intervals.size()){
            i++;
            while(i<intervals.size() && e>=intervals[i][0]){
                if(e<intervals[i][1])
                    e=intervals[i][1];
                i++;
            }
            res.push_back({s,e});
            if(i<intervals.size())
                s=intervals[i][0],e=intervals[i][1];
           }
        return res;
    }
};