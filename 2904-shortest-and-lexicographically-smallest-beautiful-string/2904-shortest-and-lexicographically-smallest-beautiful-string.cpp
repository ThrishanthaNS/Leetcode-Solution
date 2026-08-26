class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0,j=0,count=0,len=s.size();
        string ans=s;
        while(j<s.size()){
            if(s[j]=='1') count++;
            while(i<=j && count>k){
                if(s[i]=='1') count--;
                i++;
            }
            while(count==k && s[i]=='0'){
                i++;
            }
            if(count==k){
                if(j-i+1<len){
                    ans=s.substr(i,j-i+1);
                    len=j-i+1;
                }
                else if(j-i+1==len){
                    string str=s.substr(i,j-i+1);
                    if(str<ans) ans=str;
                }
            }
            j++;
        }
        return (count>=k)?ans:"";
    }
};