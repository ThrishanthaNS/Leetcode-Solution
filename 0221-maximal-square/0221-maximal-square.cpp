class Solution {
public:
    int Rectangle(vector<int>& heights) {
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
        int ans=0;
        for(int i=0;i<n;i++){
            int width=sol[i].first-sol[i].second-1;
            int height=heights[i];
            int side=min(height,width);
            ans=max(ans,side*side);
        }
        return ans;
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix[0].size();
        vector<int>height(n,0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') height[j]=0;
                else    height[j]++;
            }
            ans=max(ans,Rectangle(height));
        }
        return ans;

    }
};