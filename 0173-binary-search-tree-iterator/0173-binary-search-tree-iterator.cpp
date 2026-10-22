/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void inorder(TreeNode* root,vector<int>&order){
    if(!root) return;
    inorder(root->left,order);
    order.push_back(root->val);
    inorder(root->right,order);
}
class BSTIterator {
public:
vector<int>order;
int idx,n;
    BSTIterator(TreeNode* root) {
        inorder(root,order);
        idx=-1;
        n=order.size();
    }
    
    int next() {
        return order[++idx];
    }
    
    bool hasNext() {
        if(idx+1<n) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */