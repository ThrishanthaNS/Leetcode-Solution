class Solution {
public:
    string smallestPalindrome(string s) {
       int n=s.size();
       vector<int>ans(26,0);
       for(char x:s){
        ans[x-'a']++;
       }
       int r=0,l=n-1;
       for(int i=0;i<26;i++){
            while(ans[i]>=2){
                s[r]='a'+i;
                s[l]='a'+i;
                r++;
                l--;
                ans[i]-=2;
            }
            if(ans[i]==1){
                s[n/2]='a'+i;
            }
       }
       return s;
    }
};