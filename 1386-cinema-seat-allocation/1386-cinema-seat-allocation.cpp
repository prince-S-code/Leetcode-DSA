class Solution {
    int count(vector<int>& arr){
        bool pos1=true;
        bool pos2=true;
        bool pos3=true;
        for(auto pos:arr){
            if(pos>=2 && pos<=5) pos1=false;
            if(pos>=4 && pos<=7) pos2=false;
            if(pos>=6 && pos<=9) pos3=false;
        }
        if(pos1 && pos2 && pos3) return 2;
        if(!(pos1 || pos2 || pos3)) return 0;
        return 1;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int k=reservedSeats.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<k;i++){
            mpp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        int len=mpp.size();
        int ans=(n-len)*2;
        for(auto it:mpp){
            ans+=count(it.second);
        }
        return ans;
    }
};