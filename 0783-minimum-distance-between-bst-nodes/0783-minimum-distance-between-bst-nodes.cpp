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
    void helper(TreeNode* root,vector<int>& ans){
        if(root==nullptr){
            return;
        }
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        int diff=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            diff=min(diff,ans[i+1]-ans[i]);
        }
        return diff;
    }
};