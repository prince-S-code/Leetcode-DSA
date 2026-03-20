class Solution {
    bool is_possible(vector<int>& bloomDay,int day,int m,int k){
        int tot_bou=0;
        int start=0;
        int cons_days=0;
        int size=bloomDay.size();
        for(int i=0;i<size;i++){
            if(bloomDay[i]<=day){
                // continue;
                cons_days++;
            }else{
                if(tot_bou >=m){
                    return true;
                }
                tot_bou+=(cons_days/k);
                cons_days=0;
            }
        }
        if(tot_bou >=m){
            return true;
        }
        tot_bou+=(cons_days/k);
        if(tot_bou >=m){
            return true;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*m*k> n){
            return -1;
        }
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low +(high-low)/2;
            if(is_possible(bloomDay,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};