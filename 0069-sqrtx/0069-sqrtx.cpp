class Solution {
    bool issafe(int x,int num){
        if(1LL*x*x<=num){
            return true;
        }
        return false;
    }
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(issafe(mid,x)){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};