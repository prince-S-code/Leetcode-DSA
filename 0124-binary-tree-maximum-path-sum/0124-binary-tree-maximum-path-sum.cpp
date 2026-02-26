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
    int pathsum=INT_MIN;
    int helper(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftpathsum=max(0,helper(root->left));
        int rightpathsum=max(0,helper(root->right));
        int currpathsum=leftpathsum+rightpathsum+root->val;
        pathsum=max(pathsum, currpathsum);
        return (max(leftpathsum,rightpathsum)+root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right){
            pathsum=root->val;
            return pathsum;
        }
        helper(root);
        return pathsum;
    }
};