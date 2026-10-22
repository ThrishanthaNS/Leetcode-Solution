class WordDictionary {
public:
struct trie{
    trie* arr[26];
    bool eow;
    trie(){
        memset(arr,0,sizeof(arr));
        eow=false;
    }
};
trie* dictionary;
    WordDictionary() {
        dictionary=new trie();
    }
    
    void addWord(string word) {
        trie* node=dictionary;
        for(char c:word){
            if(node->arr[c-'a']==nullptr){
                node->arr[c-'a']=new trie();
            }
            node=node->arr[c-'a'];
        }
        
        node->eow=true;
    }
    
    bool search(string word) {
        return helper(word,dictionary);
        
    }
    bool helper(string word,trie* node){
        if(word=="") return node->eow;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(node->arr[j]!=nullptr && helper(word.substr(i+1),node->arr[j])){
                        return true;
                    }
                }
                return false;
            }
            else{
            int idx=word[i]-'a';
            if(node->arr[idx]==nullptr){
                return false;
            }
            node=node->arr[idx];
        }
        }
        return node->eow;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */