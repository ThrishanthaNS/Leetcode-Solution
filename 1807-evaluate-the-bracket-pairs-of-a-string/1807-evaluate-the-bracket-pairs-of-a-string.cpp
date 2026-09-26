class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>mp;
        for(auto& p:knowledge){
            mp[p[0]]=p[1];
        }
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                string key="";
                while(i<s.size() && s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if(mp.find(key)!=mp.end()){
                    ans+=mp[key];
                }
                else{
                    ans+='?';
                }
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};