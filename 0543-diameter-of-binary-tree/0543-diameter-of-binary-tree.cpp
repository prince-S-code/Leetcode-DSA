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
    int diameter;
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftht=height(root->left);
        int rightht=height(root->right);
        diameter=max((leftht+rightht),diameter);
        return max(leftht,rightht)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};