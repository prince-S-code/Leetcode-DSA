class Solution {
    int rob_amt(int curr_ind,int last_ind,vector<int>& nums,vector<int>& dp){
        if(curr_ind>last_ind){
            return 0;
        }
        if(dp[curr_ind]!=-1){
            return dp[curr_ind];
        }
        int taken=nums[curr_ind]+rob_amt(curr_ind+2,last_ind,nums,dp);
        int not_taken=rob_amt(curr_ind+1,last_ind,nums,dp);
        return dp[curr_ind]=max(taken,not_taken);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int first_robbed=rob_amt(0,n-2,nums,dp1);
        int second_robbed=rob_amt(1,n-1,nums,dp2);
        return max(first_robbed,second_robbed);
    }
};