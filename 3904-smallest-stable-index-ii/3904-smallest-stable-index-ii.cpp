class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> largest(n);
        vector<int> smallest(n);
        largest[0]=nums[0];
        smallest[n-1]=nums[n-1];
        int smallest_stable=-1;
        for(int i=1;i<n;i++){
            if(nums[i]>largest[i-1]) largest[i]=nums[i];
            else largest[i]=largest[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<smallest[i+1]) smallest[i]=nums[i];
            else smallest[i]=smallest[i+1];
        }
        for(int i=0;i<n;i++){
            if((largest[i]-smallest[i]) <=k){
                smallest_stable=i;
                break;
            }
        }
        return smallest_stable;
        
    }
};