class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int n=heights.size();
        vector<pair<int,int>>sol(n,{n,-1});
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(i);
            }
            else{
                while(!s.empty() && heights[s.top()]>heights[i]){
                    sol[s.top()].first=i;
                    s.pop();
                }
                s.push(i);
            }
        }
        s={};
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
            }
            else{
                while(!s.empty() && heights[i]<heights[s.top()]){
                    sol[s.top()].second=i;
                    s.pop();
                }
                s.push(i);
            }
        }
        int ans=heights[0];
        for(int i=0;i<n;i++){
            int width=sol[i].first-sol[i].second-1;
            int area=heights[i]*width;
            ans=max(ans,area);
        }
        return ans;
        
    }
};