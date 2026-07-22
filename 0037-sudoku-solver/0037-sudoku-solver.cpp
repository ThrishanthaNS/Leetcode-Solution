class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char dig){
        for(int i=0;i<9;i++){
            if(board[i][col]==dig) return false;
            if(board[row][i]==dig) return false;
        }
        row=(row/3)*3;
        col=(col/3)*3;
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                if(board[i][j]==dig) return false;
            }
        }
        return true;

    }
    bool dfs(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        int nextrow=row;
        int nextcol=col+1;
        if(nextcol==9){
            nextcol=0;
            nextrow+=1;
        }
        if(board[row][col]=='.'){
            for(char i='1';i<='9';i++){
                if(issafe(board,row,col,i)){
                    board[row][col]=i;
                    if(dfs(board,nextrow,nextcol)) return true;
                    board[row][col]='.';
                }
            }
        }
        else{
            return dfs(board,nextrow,nextcol);
        }
    return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
};