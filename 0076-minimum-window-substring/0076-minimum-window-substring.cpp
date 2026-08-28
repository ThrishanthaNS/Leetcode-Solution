class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,current;
        for(char c:t){
            need[c]++;
        }
        unordered_set<char>str;
        int right=0,left=0,start;
        int minlen=INT_MAX,formed=0,required=need.size();
        
        while(right<s.size()){
            char c=s[right];
            current[c]++;
            if(need.count(c) && current[c]==need[c]) formed++;
            if(formed==required){
                while(formed==required){
                    if(right-left+1<minlen){
                        minlen=right-left+1;
                        start=left;
                    }
                    current[s[left]]--;
                    if(need.count(s[left]) && current[s[left]]<need[s[left]]) {
                        formed--;
                    }
                    left++;
                }
            }
            right++;

        }
        return (minlen==INT_MAX)?"":s.substr(start,minlen);

    }
};