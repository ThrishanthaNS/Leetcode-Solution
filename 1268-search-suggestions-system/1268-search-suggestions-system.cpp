class Solution {
public:
vector<vector<string>>ans;
struct trie{
    trie* children[26];
    vector<int>suggestion;
    trie(){
        memset(children,0,sizeof(children));
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
}
void search(const string &word,vector<string>& products){
    trie* node=root;
    for(char c:word){
        int idx=c-'a';
        if(node)    node=node->children[idx];
        if(node){
            vector<string>res;
            for(int i:node->suggestion){
                res.push_back(products[i]);
            }
            ans.push_back(res);
        }
        else{
            ans.push_back({});
        }
    }
    
}
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        for(int i=0;i<products.size();i++){
            insert(products[i],i);
        }
        search(searchWord,products);
        return ans;

    }
};