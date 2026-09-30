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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<int>res;
        queue<pair<long long,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty()){
            auto[sum,node]=q.front();
            q.pop();
            if(!node->right && !node->left){
                res.push_back(sum*10+node->val);
            }
            else{
                if(node->right){
                    q.push({sum*10+node->val,node->right});
                }
                if(node->left){
                    q.push({sum*10+node->val,node->left});
                }
            }
        }
        int sum=accumulate(res.begin(),res.end(),0);
        return sum;
        

    }
};