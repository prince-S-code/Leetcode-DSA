/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        bool leftToright = true;
        q.push(root);
        while (q.size()) {
            int size = q.size();
            // if(leftToright){
            //     st_ind=0;
            //     end_ind=size-1;
            // }
            // else{
            //     st_ind=size-1;
            //     end_ind=0;
            // }
            vector<int> temp(size);
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                int index=leftToright?i:size-i-1;
                temp[index] = curr->val;
            }
            leftToright = !leftToright;
            ans.push_back(temp);
        }
        return ans;
    }
};