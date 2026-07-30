class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int m=n/8;
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=i*8;
        }
        ans=ans+(n%8)*(m+1);
        return ans;
    }
};