class Solution {
public:
    int maxPower(string s) {
        int ans=1,i=1,j=0;
        if(s.size()==1) return 1;
        while(i<s.size()){
            if(s[i-1]!=s[i]){
                ans=max(ans,i-j);
                j=i;
            }
            i++;
        }
        ans=max(ans,i-j);
        return ans;
    }
};