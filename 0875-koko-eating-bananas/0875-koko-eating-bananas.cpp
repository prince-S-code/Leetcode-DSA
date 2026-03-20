class Solution {
    bool is_possible(vector<int>&piles,int k,int h){
        int total_hr=0;
        int size=piles.size();
        for(int i=0;i<size;i++){
            if(total_hr>h){
                return false;
            }
            else{
                total_hr+=((piles[i]+k-1)/k);
            }
        }
        if(total_hr<=h){
            return true;
        }
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int maxi=0;
        int n=piles.size();
        for(int i=0;i<n;i++) maxi=max(maxi,piles[i]);
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_possible(piles,mid,h)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};