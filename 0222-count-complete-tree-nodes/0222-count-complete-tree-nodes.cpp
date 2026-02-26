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
    int leftht(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int ht=0;
        while(root){
            root=root->left;
            ht++;
        }
        return ht;
    }
    int rightht(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int ht=0;
        while(root){
            root=root->right;
            ht++;
        }
        return ht;
    }
public:
    int countNodes(TreeNode* root) {
        int lht=leftht(root);
        int rht=rightht(root);
        if(lht==rht){
            return (1<<rht)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};