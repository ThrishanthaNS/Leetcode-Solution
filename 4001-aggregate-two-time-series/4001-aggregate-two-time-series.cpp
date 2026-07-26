class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int s1=0,s2=0;
        vector<vector<int>>ans;
        int n1=series1.size(),n2=series2.size();
        int timestamp=min(series1[0][0],series2[0][0]);
        int num1=0,num2=0;
        while(s1<n1 ||s2<n2){
            while(s1<n1 && series1[s1][0]<timestamp){
                s1++;
            }
            if(s1==n1) num1=0;
            else num1=series1[s1][1];
            
            while(s2<n2 && series2[s2][0]<timestamp){
                s2++;
            }
            if(s2==n2) num2=0;
            else num2=series2[s2][1];
            ans.push_back({timestamp,num1+num2});
            if( s1<n1 && series1[s1][0]==timestamp) s1++;
            if(s2<n2 && series2[s2][0]==timestamp) s2++;
            if(s1<n1 && s2<n2){
                timestamp=min(series1[s1][0],series2[s2][0]);
            }
            else if(s1<n1){
                timestamp=series1[s1][0];
            }
            else if(s2<n2){
                timestamp=series2[s2][0];
            }
        }
        return ans;
    }
};