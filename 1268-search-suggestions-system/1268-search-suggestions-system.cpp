class Solution {
public:
struct trie{
    trie* children[26];
    vector<int>suggestion;
    bool eow;
    trie(){
        memset(children,0,sizeof(children));
        eow=false;
    }
};
trie* root=new trie(); 
void insert(const string &word,int index){
    trie* node=root;
    for(char c:word){
        int idx=c-'a';
        if(node->children[idx]==nullptr){
            node->children[idx]=new trie();
        }
        node=node->children[idx];
        if(node->suggestion.size()<3)   node->suggestion.push_back(index);

    }
    node->eow=true;
}
vector<string>search(const string &word,vector<string>& products){
    trie* node=root;
    vector<string>res;
    for(char c:word){
        int idx=c-'a';
        if(node->children[idx]==nullptr){
            return res;
        }
        node=node->children[idx];
    }
    for(int i:node->suggestion){
        res.push_back(products[i]);
    }
    return res;
    
}
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        for(int i=0;i<products.size();i++){
            insert(products[i],i);
        }
        string prefix="";
        for(char c:searchWord){
            prefix+=c;
            vector<string>res;
            res=search(prefix,products);
            ans.push_back(res);
        }
        return ans;

    }
};