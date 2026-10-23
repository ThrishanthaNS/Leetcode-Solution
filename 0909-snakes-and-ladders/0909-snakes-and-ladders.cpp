class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int target=n*n;
        queue<pair<int,int>>q;
        vector<int>vis(target+1,0);
        q.push({1,0});
        vis[1]=1;
        while(!q.empty()){
            auto [curr,move]=q.front();
            q.pop();
            if(curr==target) return move;
            for(int i=1;i<=6;i++){
                int next=curr+i;
                if(next>target) continue;
                int x=next-1;
                int rowfrombottom=x/n;
                int row=n-rowfrombottom-1;
                int col=x%n;
                if(rowfrombottom%2==1){
                    col=n-col-1;
                }
                if(board[row][col]!=-1){
                    next=board[row][col];
                }
                if(!vis[next]){
                    vis[next]=1;
                    q.push({next,move+1});
                }
            }
        }
        return -1;
    }

};