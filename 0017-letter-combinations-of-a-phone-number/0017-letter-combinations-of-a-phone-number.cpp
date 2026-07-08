class Solution {
public:
    vector<string>ans;
    unordered_map<char,string>mp{
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void dfs(string &current,int index,string &digits){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        for(char c:mp[digits[index]]){
            current.push_back(c);
            dfs(current,index+1,digits);
            current.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
        string curr;
        dfs(curr,0,digits);
        return ans;

    }
};