class Solution {
public:
    void makezero(vector<vector<int>>& matrix,int idx,int r){
        if(r){
            for(int i=0;i<matrix[0].size();i++){
                matrix[idx][i]=0;
            }
        }
        else{
            for(int i=0;i<matrix.size();i++){
                matrix[i][idx]=0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int firstrow=0,firstcol=0;
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0) {
                firstrow=1;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) {
                firstcol=1;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                makezero(matrix,i,1);
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0){
                makezero(matrix,i,0);
            }
        }
        if(firstrow){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(firstcol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};