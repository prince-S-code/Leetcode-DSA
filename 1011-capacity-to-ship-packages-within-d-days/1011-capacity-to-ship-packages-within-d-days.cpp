class Solution {
    bool is_possible(vector<int>& weights,int guess,int days){
        int days_req=0;
        int curr_sum=0;
        for(int i=0;i<weights.size();i++){
                curr_sum+=weights[i];
            if(curr_sum>guess){
                curr_sum=weights[i];
                days_req++;
            }
        }
        days_req++;
        if(days_req <=days){
            return true;
        }
        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_possible(weights,mid,days)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};