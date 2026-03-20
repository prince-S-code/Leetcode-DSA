class Solution {
    bool is_possible(vector<int> &nums,int div,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum>threshold){
                return false;
            }
            sum+=(nums[i]+div-1)/div;
        }
        if(sum<=threshold){
            return true;
        }
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=1e7;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_possible(nums,mid,threshold)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};