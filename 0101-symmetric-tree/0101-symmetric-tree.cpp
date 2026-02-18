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
    bool isMirror(TreeNode* p,TreeNode* q){
        if(p==nullptr || q==nullptr){
            return p==q;
        }
        return isMirror(p->left,q->right) && isMirror(p->right,q->left) && p->val==q->val;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return isMirror(root->left,root->right);
    }
};