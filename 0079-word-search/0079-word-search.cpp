class Solution {
public:
vector<int>di={0,-1,1,0};
vector<int>dj={-1,0,0,1};
bool ismatch(vector<vector<char>>&board,string &word,int i,int j,int idx,vector<vector<int>>&vis){
    if(idx==word.size()) return true;
    if(i<0 || i>=board.size()||j<0 ||j>=board[0].size()) return false;
    if(vis[i][j]) return false;
    if(board[i][j]!=word[idx]) return false;
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int ix=i+di[k];
        int jx=j+dj[k];
        if(ismatch(board,word,ix,jx,idx+1,vis)){
            return true;
        }
    }
    vis[i][j]=0;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(ismatch(board,word,i,j,0,vis)){
                        return  true;
                    }
                }
            }
        }
        return false;
    }
};