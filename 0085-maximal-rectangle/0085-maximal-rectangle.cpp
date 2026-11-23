class Solution {
public:

int Rectangle(vector<int>& heights) {
    int n = heights.size(), ans = 0;
    stack<int> s;

    for (int i = 0; i <= n; i++) {
        while (!s.empty() && (i == n || heights[s.top()] > heights[i])) {
            int h = heights[s.top()];
            s.pop();

            int width = s.empty() ? i : i - s.top() - 1;
            ans = max(ans, h * width);
        }
        s.push(i);
    }

    return ans;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
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