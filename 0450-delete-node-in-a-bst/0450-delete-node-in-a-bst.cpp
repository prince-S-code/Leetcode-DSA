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
    TreeNode* inorder_successor(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr; 
        }
        // three cases for the comparision of the root val with the key
        if(root->val > key){
            root->left= deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right=deleteNode(root->right,key);
        }
        else{ // case when the key == root->val
            // three cases for the deletion of the node
            // if no child od the node
            if(!root->left && !root->right){
                return nullptr;
            }
            // only one child
            if(!root->left){
                return root->right;
            }else if(!root->right){
                return root->left;
            }

            // both the child present
            TreeNode* successor=inorder_successor(root->right);
            root->val=successor->val;
            root->right=deleteNode(root->right,successor->val);
        }
        return root;
    }
};