class Solution {
    int count(int n){
        int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            ans[i]=count(i);
        }
        return ans;
    }
};