/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // child to parent linking
        // mpp[child] = parent of the child 
        unordered_map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*>parent;
        parent.push(root);
        while(parent.size()){
            TreeNode* curr=parent.front();
            parent.pop();
            if(curr->left){
                parent.push(curr->left);
                mpp[curr->left]=curr;
            }
            if(curr->right){
                parent.push(curr->right);
                mpp[curr->right]=curr;
            }
        }

        // bfs from the target to outwards direction not visited ones;
        set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int dis=0;
        while(q.size()){
            if(dis==k){
                break;
            }
            dis++;
            int currsize=q.size();
            for(int i=0;i<currsize;i++){
                TreeNode* curr=q.front();
                q.pop();
                // left
                if(curr->left && !visited.count(curr->left)){
                    q.push(curr->left);
                    visited.insert(curr->left);
                    
                }
                // right
                if(curr->right && !visited.count(curr->right)){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                // parent
                if(mpp.count(curr) && !visited.count(mpp[curr])){
                    q.push(mpp[curr]);
                    visited.insert(mpp[curr]);
                }
            }
        }
        vector<int> ans;
        while(q.size()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};