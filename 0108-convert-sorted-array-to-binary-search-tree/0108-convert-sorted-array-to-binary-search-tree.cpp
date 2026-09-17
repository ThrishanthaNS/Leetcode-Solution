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
    TreeNode* solve(int left,int right,vector<int>&num){
        if(left>right) return nullptr;
        int mid=left+(right-left)/2;
        TreeNode* node=new TreeNode(num[mid]);
        node->left=solve(left,mid-1,num);
        node->right=solve(mid+1,right,num);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};