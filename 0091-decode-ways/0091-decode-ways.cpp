class Solution {
    int solve(int ind,int n,string& s,vector<int>& dp){
        // base cases
        if(s[ind]=='0') return 0;
        if (ind==n) return 1;

        if(dp[ind]!=-1) return dp[ind];

        int take_one=solve(ind+1,n,s,dp);
        int take_2=0;
        if(ind+1 < n){
            int num=((s[ind]-'0')*10+(s[ind+1]-'0'));
            if(num>=10 && num<=26){
                take_2=solve(ind+2,n,s,dp);
            }
        }
        return dp[ind]=take_one+take_2;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp);
    }
};