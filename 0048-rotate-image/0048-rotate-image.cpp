class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int left=0,right=n-1;left<right;left++,right--){
            for(int i=0;i<n;i++) 
                swap(matrix[i][left],matrix[i][right]);
            }
    }
};