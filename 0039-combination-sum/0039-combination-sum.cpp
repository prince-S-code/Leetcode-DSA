class Solution {
    void solve(int ind,int target,vector<int>& candidates,vector<int>& curr,vector<vector<int>>& ans){
        int n=candidates.size();
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(ind==n){
            return;
        }
        solve(ind+1,target,candidates,curr,ans);
        if(target >= candidates[ind]){
            curr.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],candidates,curr,ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        // vector<vector<int>> dp(n);
        solve(0,target,candidates,curr,ans);
        return ans;
    }
};