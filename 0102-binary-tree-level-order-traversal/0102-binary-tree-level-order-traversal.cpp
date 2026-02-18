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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;//temporary vector for each level
        // queue initialisation
        queue<TreeNode*> q;
        // jab tak queue empty nahi ho raha tab tak continue karo;
        // null values ko push karne ki jaroorat nahi hai
        if(!root)
            return ans;

        q.push(root);
        // nullptr pushed to keep track of the levels
        // otherwise we can't distinguish the different levels
        q.push(nullptr);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                // case 1: when the queue still has elements but the level changes now
                ans.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    // q.push(nullptr); for the level breaking
                    q.push(nullptr);
                    continue;
                }
                // the case when last nullptr remaining in the queue
                // marking the end of the last level 
                else {
                    break;
                }
            } 
            // else {
                temp.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            // }
        }
        return ans;
    }
};