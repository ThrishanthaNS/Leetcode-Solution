class Solution {
public:
bool issafe(vector<string>&board,int row,int col,int n){
    //horizontal check
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q') return false;
    }
    //vertical check
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q') return false;
    }
    //left daigonal check
    for(int i=0;i<n;i++){
        if(row-i<0 || col-i<0) break;
        if(board[row-i][col-i]=='Q') return false;
    }
    //right daigonal check

    for(int i=0;i<n;i++){
        if(row-i<0 || col+i>=n) break;
        if(board[row-i][col+i]=='Q') return false;
    }
    return true;

}

void isqueen(vector<string>&board,int row,int n,vector<vector<string>>&ans){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(issafe(board,row,j,n)){
            board[row][j]='Q';
            isqueen(board,row+1,n,ans);
            board[row][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        isqueen(board,0,n,ans);
        return ans;

    }
};