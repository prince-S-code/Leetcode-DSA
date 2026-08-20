class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]<nums[n-1]) return nums[0];
        // if(nums[n-1]<nums[n-2]) return nums[n-1];
        int low=0;
        int high=n-1; 
        int index=0; 
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid]>=nums[low]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return 0;
    }
};