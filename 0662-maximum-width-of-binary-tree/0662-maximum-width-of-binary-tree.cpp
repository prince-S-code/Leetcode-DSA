class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        long long maxwidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;

            long long first, last;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                long long ind = q.front().second - start;  // NORMALIZE
                q.pop();

                if(i == 0) first = ind;
                if(i == size - 1) last = ind;

                if (curr->left)
                    q.push({curr->left, 2 * ind + 1});

                if (curr->right)
                    q.push({curr->right, 2 * ind + 2});
            }

            maxwidth = max(maxwidth, last - first + 1);
        }

        return (int)maxwidth;
    }
};