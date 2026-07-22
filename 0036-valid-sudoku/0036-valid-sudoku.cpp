class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char dig){
        int count=0;
        for(int i=0;i<9;i++){
            if(board[i][col]==dig) count++;
            if(board[row][i]==dig) count++;
        }
        row=(row/3)*3;
        col=(col/3)*3;
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                if(board[i][j]==dig) count++;
            }
        }
        return count==3;

    }
    bool dfs(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        int nextrow=row;
        int nextcol=col+1;
        if(nextcol==9){
            nextcol=0;
            nextrow+=1;
        }
        if(board[row][col]!='.'){
            if(issafe(board,row,col,board[row][col])){
                return dfs(board,nextrow,nextcol);
            }
            else {
                return false;
            }
        }
        else
            return dfs(board,nextrow,nextcol);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return dfs(board,0,0);
    }
};