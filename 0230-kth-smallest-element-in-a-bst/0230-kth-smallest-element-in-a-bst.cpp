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
    int ans=-1;
    void helper(TreeNode* root,int & k){
        if(root==nullptr || ans!=-1){
            return;
        }
        // if(ans!=-1){
        //     return ans;
        // }
        helper(root->left,k);
        k--;
        if(k==0){
            ans=root->val;
        }
        // ans.push_back(root->val);
        helper(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> ans;
        helper(root,k);
        return ans;
    }
};