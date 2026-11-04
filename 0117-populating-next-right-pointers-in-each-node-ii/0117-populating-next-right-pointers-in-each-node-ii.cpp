/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        vector<vector<Node*>>vec;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<Node*>v;
            for(int i=0;i<size;i++){
                Node* n=q.front();
                q.pop();
                v.push_back(n);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }  
            vec.push_back(v);          
        }
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size()-1;j++){
                Node* node=vec[i][j];
                node->next=vec[i][j+1];
            }
        }
        return root;
    }
};