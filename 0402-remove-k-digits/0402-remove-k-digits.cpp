class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int count=0;
        for(char c:num){
            while(!s.empty() && count<k && (s.top()-'0')>(c-'0')){
                s.pop();
                count++;
            }
            s.push(c);
            
        }
        
        while(!s.empty() && count<k){
            s.pop();
            count++;
        }
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
           i++;
        }
        ans=ans.substr(i);
        return (ans.empty())?"0":ans;
        
        
        
    }
};