class Solution {
    void solve(vector<int>& candidates, int ind,int target,vector<int>& temp,vector<vector<int>>&ans){
        if(ind == candidates.size() || target<0){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[ind]);
        solve(candidates,ind,target-candidates[ind],temp,ans);
        temp.pop_back();
        solve(candidates,ind+1,target,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,0,target,temp,ans);
        return ans;
    }
};