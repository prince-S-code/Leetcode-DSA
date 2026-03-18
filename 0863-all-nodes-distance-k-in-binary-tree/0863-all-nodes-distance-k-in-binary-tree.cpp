class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // child to parent linking
        unordered_map<TreeNode*,TreeNode*> mpp;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                if(curr->left){
                    mpp[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    mpp[curr->right]=curr;
                    q.push(curr->right);
                }
                q.pop();
            }
        }
        vector<int> ans;
        queue<TreeNode*> que;
        int dis=0;
        que.push(target);
        visited.insert(target);
        while(!que.empty()){
            if(dis==k){
                break;
            }
            dis++;
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=que.front();
                que.pop();
                if(curr->left && visited.count(curr->left)==0){
                    que.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right && visited.count(curr->right)==0){
                    que.push(curr->right);
                    visited.insert(curr->right);
                }
                if(mpp.find(curr)!=mpp.end() && visited.count(mpp[curr])==0){
                    que.push(mpp[curr]);
                    visited.insert(mpp[curr]);
                }
            }
        }
        while(!que.empty()){
            ans.push_back(que.front()->val);
            que.pop();
        }
        return ans;
    }
};