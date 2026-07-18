class Solution {
public:
int ans=0;
bool issafe(vector<string>&board,int row,int col,int n){

    //vertical check
    for(int i=0;i<row;i++){
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

void isqueen(vector<string>&board,int row,int n){
    if(row==n){
        ans++;
        return;
    }
    for(int j=0;j<n;j++){
        if(issafe(board,row,j,n)){
            board[row][j]='Q';
            isqueen(board,row+1,n);
            board[row][j]='.';
        }
    }
}
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        isqueen(board,0,n);
        return ans;
    }
};