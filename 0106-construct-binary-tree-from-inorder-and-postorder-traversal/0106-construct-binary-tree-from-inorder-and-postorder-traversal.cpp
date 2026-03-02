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
    unordered_map<int,int> mpp;
    int postIndex;
    TreeNode* helper(vector<int>& postorder,int left,int right){
        if(left>right){
            return nullptr;
        }
        int position=mpp[postorder[postIndex]];
        TreeNode* root=new TreeNode(postorder[postIndex--]);
        root->right=helper(postorder,position+1,right);
        root->left=helper(postorder,left,position-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        int left=0;
        int right=n-1;
        postIndex=n-1;
        return helper(postorder,left,right);
    }
};