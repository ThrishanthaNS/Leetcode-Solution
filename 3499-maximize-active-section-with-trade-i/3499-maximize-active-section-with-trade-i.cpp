class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int cnt1=count(s.begin(),s.end(),'1');
        int i=0,bestgain=0,prev=INT_MIN,cur=0;
        while(i<n){
            int start=i;
            while(i<n && s[i]==s[start]){
                i++;
            }
            if(s[start]=='0'){
                cur=i-start;
                bestgain=max(bestgain,cur+prev);
                prev=cur;
            }
        }
        return cnt1+bestgain;

    }
};