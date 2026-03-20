class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0){
            return false;
        }
        int req_sum=total_sum/2;
        int m=nums.size();
        int rows_req=req_sum+1;
        vector<vector<bool>>dp(m,vector<bool>(rows_req,false));
        for(int i=0;i<m;i++){
            dp[i][0]=true;
        }
        if(nums[0]<rows_req) dp[0][nums[0]]=true;
        for(int i=1;i<m;i++){
            for(int j=1;j<=req_sum;j++){
                bool not_take=dp[i-1][j];
                bool take=false;
                if(nums[i]<j)
                    take=dp[i-1][j-nums[i]];//take case
                dp[i][j]=take||not_take;
            }
        }
        return dp[m-1][req_sum];
    }
};