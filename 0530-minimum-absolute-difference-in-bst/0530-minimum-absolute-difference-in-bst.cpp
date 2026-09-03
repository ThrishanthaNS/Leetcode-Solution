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
    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX;
        queue<TreeNode*>q;
        vector<int>ele;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ele.push_back(node->val);
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
        }
        sort(ele.begin(),ele.end());
        for(int i=1;i<ele.size();i++){
            res=min(res,ele[i]-ele[i-1]);
        }
        return res;
    }
};