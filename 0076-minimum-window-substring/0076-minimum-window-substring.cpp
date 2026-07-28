class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int>need,window;
       for(char c:t){
        need[c]++;
       }
       int l=0,r=0;
       int minlen=INT_MAX;
       int start=0;
       int formed=0,required=need.size();
       while(r<s.size()){
            char c=s[r];
            window[c]++;
            if(need.count(c) && need[c]==window[c]){
                formed++;
            }
            while(formed==required){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    start=l;
                }
                window[s[l]]--;
                if(need.count(s[l]) && window[s[l]]<need[s[l]]){
                    formed--;
                }
                l++;
            }
            r++;
        }
        return (minlen==INT_MAX)?"":s.substr(start,minlen);

    }
};