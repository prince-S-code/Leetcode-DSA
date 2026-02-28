class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=0;
        int rightmax=0;
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<right){
            leftmax=max(height[left],leftmax);
            rightmax=max(height[right],rightmax);
            if(leftmax<=rightmax){
                ans+=leftmax-height[left];
                left++;
            }
            else{
                ans+=rightmax-height[right];
                right--;
            }
        }
        return ans;
    }
};