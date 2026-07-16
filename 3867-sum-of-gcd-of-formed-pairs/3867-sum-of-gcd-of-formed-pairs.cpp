class Solution {
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix_max(n);
        vector<int> prefix_gcd(n);
        prefix_max[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>prefix_max[i-1]){
                prefix_max[i]=nums[i];
            }else{
                prefix_max[i]=prefix_max[i-1];
            }
        }
        for(int i=0;i<n;i++){
            prefix_gcd[i]=gcd(nums[i],prefix_max[i]);
        }
        sort(prefix_gcd.begin(),prefix_gcd.end());
        long long sum=0;
        for(int i=0;i<n/2;i++){
            sum+=gcd(prefix_gcd[i],prefix_gcd[n-1-i]);
        }
        return sum;
    }
};