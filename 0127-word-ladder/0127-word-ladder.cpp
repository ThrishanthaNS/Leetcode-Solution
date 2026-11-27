class Solution {
public:
bool isadj(string& word,string& pattern){
    int count=0;
    for(int i=0;i<word.size();i++){
        if(word[i]!=pattern[i]){
            count++;
        }
    }
    return count==1;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>mp;
        wordList.push_back(beginWord);
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++ ){
                if(isadj(wordList[i],wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>vis;
        vis.insert(beginWord);
        while(!q.empty()){
            auto [word,steps]=q.front();
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(string next:mp[word]){
                if(!vis.count(next)){
                    q.push({next,steps+1});
                    vis.insert(next);
                }
            }
        }
        return 0;

        
    }
};