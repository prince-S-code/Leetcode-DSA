class Solution {
    void node_finder(TreeNode* curr,int k,set<TreeNode*>& st,vector<int>& ans,unordered_map<TreeNode*,TreeNode*> child_parent){
        if(k==0){
            ans.push_back(curr->val);
            return;
        }
        if(curr->left && st.count(curr->left)==0){
            st.insert(curr->left);
            node_finder(curr->left,k-1,st,ans,child_parent);
        }
        if(curr->right && st.count(curr->right)==0){
            st.insert(curr->right);
            node_finder(curr->right,k-1,st,ans,child_parent);
        }
        if(child_parent[curr] && st.count(child_parent[curr])==0){
            st.insert(child_parent[curr]);
            node_finder(child_parent[curr],k-1,st,ans,child_parent);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // do level order traversal for making the unordered_mapping of child to parent
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> child_parent;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    child_parent[curr->left]=curr;
                }
                if(curr->right){
                    q.push(curr->right);
                    child_parent[curr->right]=curr;
                }
            }
        }
        set<TreeNode*> visited;
        visited.insert(target);
        vector<int> ans;
        node_finder(target,k,visited,ans,child_parent);
        return ans;
    }
};