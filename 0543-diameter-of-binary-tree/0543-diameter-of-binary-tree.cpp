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
class Solution {
public:
int rightdepth(TreeNode* root,int depth){
    if(!root) return depth;
    return max(rightdepth(root->right,depth+1),rightdepth(root->left,depth+1));
}
int leftdepth(TreeNode* root,int depth){
    if(!root) return depth;
    return max(leftdepth(root->right,depth+1),leftdepth(root->left,depth+1));
}
    int diameterOfBinaryTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(!node) continue;
            int right=rightdepth(node->right,0);
            int left=leftdepth(node->left,0);
            if((right+left)>ans){
                ans=right+left;
            }
            q.push(node->right);
            q.push(node->left);
        }
        return ans;
    }
};